import numpy as np
import matplotlib.pyplot as plt
from wasm_utils import load_wasm, cleanup_wasm

def test_balckman_f64_precsion(load_wasm, cleanup_wasm):
    wasm = load_wasm
    window_size = 1024
    pointer = wasm.alloc_array(dtype=np.dtype(np.float64), length=window_size)
    wasm.instance.exports.window_blackamn_f64(pointer.address, window_size)
    test_window = wasm.read_array(pointer)
    reference_window = np.blackman(window_size)
    np.testing.assert_allclose(test_window, reference_window, rtol=1e-7)


def test_balckman_works_for_small_input(load_wasm, cleanup_wasm):
    wasm = load_wasm
    window_size = 3
    pointer = wasm.alloc_array(dtype=np.dtype(np.float64), length=window_size)
    wasm.instance.exports.window_blackamn_f64(pointer.address, window_size)
    test_window = wasm.read_array(pointer)
    reference_window = np.blackman(window_size)
    np.testing.assert_allclose(test_window, reference_window, rtol=1e-7)

#ax = plt.subplot()
#ax.plot(reference_window, color='k')
#ax.plot(test_window, color='r')
#plt.show()



