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
	@for t in $(TEST_BINS); do \
		echo "Running $$t..."; \
		./$$t || exit 1; \
	done
	@echo "All tests passed."

# Run a single test
atest: $(BUILD_DIR)/$(TEST_NAME)
	@echo "Running $(TEST_NAME)..."
	./$<

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test atest clean
