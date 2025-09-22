# Compiler and flags
CC      = clang
CFLAGS  = -std=c99 -Wall -Wextra -Iinclude -g
AR      = ar
ARFLAGS = rcs

# Directories
SRC_DIR        = src
TEST_DIR       = test
BUILD_DIR      = build
BUILD_TEST_DIR = $(BUILD_DIR)/test
LIB_NAME       = libsample.a

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Test sources and object files
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.c=$(BUILD_TEST_DIR)/%.o)
TEST_BINS = $(TEST_SRCS:$(TEST_DIR)/%.c=$(BUILD_TEST_DIR)/%)

# Default target: build library
.PHONY: all
all: $(BUILD_DIR)/$(LIB_NAME)

# Build static library
$(BUILD_DIR)/$(LIB_NAME): $(OBJS) | $(BUILD_DIR)
	$(AR) $(ARFLAGS) $@ $^

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run all tests
.PHONY: test
test: $(TEST_BINS)
	@echo "Running all tests..."
	@PASS_COUNT=0; TOTAL_COUNT=0; \
	for t in $(TEST_BINS); do \
		name=$$(basename $$t); \
		TOTAL_COUNT=$$((TOTAL_COUNT+1)); \
		printf "Testing $$name... "; \
		output=$$($$t 2>&1); \
		status=$$?; \
		if [ $$status -eq 0 ]; then \
			echo "PASSED"; \
			PASS_COUNT=$$((PASS_COUNT+1)); \
		else \
			echo "FAILED"; \
			echo "$$output"; \
		fi; \
	done; \
	echo "$$PASS_COUNT / $$TOTAL_COUNT tests passed."

# Compile test object files
$(BUILD_TEST_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_TEST_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link test binaries
$(BUILD_TEST_DIR)/%: $(BUILD_TEST_DIR)/%.o $(OBJS) | $(BUILD_TEST_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Run a single test by name
.PHONY: test-%
test-%: $(BUILD_TEST_DIR)/%
	@name=$*; \
	printf "Testing $$name... "; \
	output=$$($< 2>&1); \
	status=$$?; \
	if [ $$status -eq 0 ]; then \
		echo "PASSED"; \
	else \
		echo "FAILED"; \
		echo "$$output"; \
	fi

# Create build directories if not exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_TEST_DIR):
	mkdir -p $(BUILD_TEST_DIR)

# Clear build artifacts
.PHONY: clear
clear:
	rm -rf $(BUILD_DIR)

