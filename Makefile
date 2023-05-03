CC := clang
LD := wasm-ld

DISSASEMBLER := wasm2wat
DECOMPILER := wasm-decompile

EXEC_NAME := dsp_lib

RELEASE_EXEC := ${EXEC_NAME}.wasm
TEST_EXEC := test_${EXEC_NAME}.wasm
TEST_MAP := test_${EXEC_NAME}.map
TEST_REPORT_FILENAME := test_resport.xml

BUILD_DIR := ./build
SRC_DIRS := ./src
TEST_DIR := ./test

SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
TESTS := $(shell find $(TEST_DIR) -name *.py)


INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS := --target=wasm32 $(INC_FLAGS) -Wall -Wextra -nostdlib -O3 -flto -ffunction-sections -fdata-sections -std=c2x

LDFLAGS_RELEASE := --no-entry --lto-O3 --gc-sections --strip-all 
LDFLAGS_TEST := --no-entry --lto-O3 --no-gc-sections --export-all -Map $(BUILD_DIR)/$(TEST_MAP)

# link release
$(BUILD_DIR)/$(RELEASE_EXEC): $(OBJS)
	$(LD) $(OBJS) -o $@ $(LDFLAGS_RELEASE)

# link test
$(BUILD_DIR)/$(TEST_EXEC): $(OBJS)
	$(LD) $(OBJS) -o $@ $(LDFLAGS_TEST)

# compile
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


# wat dissasembly
$(BUILD_DIR)/$(RELEASE_EXEC).wat: $(BUILD_DIR)/$(RELEASE_EXEC)
	$(DISSASEMBLER)  $(BUILD_DIR)/$(RELEASE_EXEC) -o $(BUILD_DIR)/$(RELEASE_EXEC).wat

# decompile to c like syntax
$(BUILD_DIR)/$(RELEASE_EXEC).dcmp: $(BUILD_DIR)/$(RELEASE_EXEC)
	$(DECOMPILER)  $(BUILD_DIR)/$(RELEASE_EXEC) -o $(BUILD_DIR)/$(RELEASE_EXEC).dcmp

# run test suite
$(BUILD_DIR)/$(TEST_REPORT_FILENAME): $(BUILD_DIR)/$(TEST_EXEC) $(TESTS)
	pytest -v -s --junitxml=$(BUILD_DIR)/$(TEST_REPORT_FILENAME)


build: $(BUILD_DIR)/$(RELEASE_EXEC)

test: $(BUILD_DIR)/$(TEST_REPORT_FILENAME)

asm: $(ASMS)

dissasemble: $(BUILD_DIR)/$(RELEASE_EXEC).wat

decompile: $(BUILD_DIR)/$(RELEASE_EXEC).dcmp


.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)


default: all

MKDIR_P ?= mkdir -p
