# Compiler and flags
CC = clang
CFLAGS = -std=c99 -Wall -Wextra -Iinclude -g

# Directories
SRC_DIR   = src
TEST_DIR  = test
BUILD_DIR = build

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Test sources and binaries
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_BINS = $(TEST_SRCS:$(TEST_DIR)/%.c=$(BUILD_DIR)/%)

# Default target: build everything
all: $(BUILD_DIR) $(OBJS) $(TEST_BINS)

# Build object files from src
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build test binaries
$(BUILD_DIR)/%: $(TEST_DIR)/%.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run all test binaries
test: all
	@total=0; passed=0; failed=0; failed_list=""; \
	for t in $(TEST_BINS); do \
		name=$$(basename $$t); \
		total=$$((total+1)); \
		echo ">>> Running test: $$name"; \
		echo ""; \
		if ./$$t; then \
			echo "[PASS] $$name"; \
			passed=$$((passed+1)); \
		else \
			echo "[FAIL] $$name"; \
			failed=$$((failed+1)); \
			failed_list="$$failed_list $$name"; \
		fi; \
		echo ""; \
	done; \
	if [ $$failed -eq 0 ]; then \
		echo "All tests PASSED"; \
	else \
		echo "The following tests FAILED:$$failed_list"; \
	fi; \
	echo "Summary: $$total tests, $$passed passed, $$failed failed"; \
	if [ $$failed -ne 0 ]; then exit 1; fi

# Run a single test
atest: $(BUILD_DIR)/$(TEST_NAME)
	@echo ">>> Running test: $(TEST_NAME)";
	@echo "";
	@if ./$(BUILD_DIR)/$(TEST_NAME); then \
		echo "[PASS] $(TEST_NAME)"; \
	else \
		echo "[FAIL] $(TEST_NAME)"; \
	fi

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test atest clean
