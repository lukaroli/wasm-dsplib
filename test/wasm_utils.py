import numpy as np
from wasmer import Store, Module, Instance, ImportObject, Function, Type, FunctionType
from dataclasses import dataclass
import pytest


@pytest.fixture(scope="session")
def load_wasm():
    return wasm_utils("build/test_dsp_lib.wasm")

@pytest.fixture()
def cleanup_wasm(load_wasm, request):
    def cleanup():
        load_wasm.instance.exports.bump_freeall()
    request.addfinalizer(cleanup)
    


@dataclass
class wasm_pointer():
    address: int
    dtype: np.dtype
    length: int

    def bytesize(self):
        return self.dtype.itemsize * self.length


class wasm_utils():
    def __init__(self, path: str):
        wasm = open(path, "rb").read()
        store = Store()
        module = Module(store, wasm)
        import_object = ImportObject()
        import_object.register(
            "env",
            {
                "js_cos": Function(store, np.cos, FunctionType([Type.F64], [Type.F64]))
            }
        )
        self.instance = Instance(module, import_object)
        self.memory = self.instance.exports.memory

    def alloc_array(self, dtype: np.dtype, length: int):
        return wasm_pointer(address=self.instance.exports.bump_alloc(length * dtype.itemsize),
                            dtype=dtype,
                            length=length)

    def read_array(self, array: wasm_pointer):
        buffer = bytearray(self.memory.buffer)
        return np.frombuffer(buffer,
                             dtype=array.dtype,
                             count=array.length,
                             offset=array.address)
