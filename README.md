# Data Structure in C

**C library of data structures** for exploring and implementing data structures and algorithms.
Based on *C99*

## Features

## Getting started
1. Navigate to the project directory
```shell
cd path/to/project
```
2. Build the project
```shell
make
```
3. Test
```shell
# Run all tests
make test

# Run a single test
make test-<target>
```
> Replace the `target` with the name of the test you want to run
4. Clear build artifacts
```shell
make clear
```

## Project Structure
```
data-structure-in-c  
├── include/    # Header files
├── src/        # Implementation
├── test/       # Test files
├── build/      # Build artifacts
├── Makefile  
└── README.md  
```

## Project Guidelines

### Naming Conventions
- Structs: `PascalCase`
- Functions: Use `snake_case` with the data structure name as prefix (e.g., `stack_push()`)
- Test files: end with `_test.c` (e.g., `dequeue_test.c`)

### Test Strategy

#### AAA(Arrange-Act-Assert)
1. Arrange: Set up the test data, environment and initialize
2. Act: call the function under test
3. Assert: check the result
```c
void test_stack_push() {
    // Arrange
    Stack stack;
    stack_init(&stack);

    // Act
    stack_push(&stack, 42);

    // Assert
    assert(stack_top(&stack) == 42);
}
```

### Documentation

#### Doxygen-style
```c
/**
 * @file addition.c
 * @brief Basic integer addition and 2D point demonstration.
 *
 * This module provides a simple integer addition function and a
 * 2D Point structure example. It is intended to illustrate proper
 * Doxygen documentation style for the C project.
 *
 * @author Jihoon
 * @date 2025-09-22
 * @version 0.0.0
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Point
 * @brief Represents a point in 2D Cartesian coordinates.
 *
 * This structure is used to demonstrate Doxygen documentation
 * for data types in C. Coordinates are integers.
 */
typedef struct {
    int x; /**< X coordinate */
    int y; /**< Y coordinate */
} Point;

/**
 * @brief Adds two integers.
 *
 * Computes the sum of two integers and returns the result.
 * 
 * @note Overflow behavior is undefined. For large values near
 * INT_MAX or INT_MIN, the result may wrap around.
 *
 * @param a First integer operand.
 * @param b Second integer operand.
 * @return Sum of @p a and @p b.
 */
int add(int a, int b) {
    return a + b;
}

/**
 * @brief Entry point of the program demonstrating addition.
 *
 * Demonstrates:
 * 1. Creation of a Point structure (example usage).
 * 2. Addition of two integers using @ref add().
 * 3. Printing results to the console.
 *
 * @return Returns 0 on success.
 */
int main(void) {
    Point p = {3, 4}; /**< Example Point instance (unused in calculations) */

    int x = 10; /**< First integer to add */
    int y = 5;  /**< Second integer to add */

    printf("add(%d, %d) = %d\n", x, y, add(x, y));

    return 0;
}
```

### Versioning

#### Semantic versioning
- Major: Incompatible API changes
- Minor: Backward-compatible changes
- Patch: bugfixes, tiny update

## Repository Guidelines

### Commit Message Prefix
- `Feat`: New feature
- `Fix`: Bug fix
- `Docs`: Documentation update
- `Refactor`: Code refactoring
- `Test`: Unit tests
- `Chore`: Other maintenance tasks

### Branch Strategy
- `main`: Stable releases
- `dev`: Development and testing
- `feature/`: New feature implementation
- `hotfix/`: Urgent fixes

### Merge Strategy
1. `feature` -> `dev`
	- Open a Pull Request to `dev`
	- Ensure tests pass
	- Squash and merge with feature name
2. `dev` -> `main`
	- Open a Pull Request to `main`
	- Ensure code review and tests pass
	- Merge commit with signature
3. `hotfix`
	- Apply urgent fix, merge into `main`
	- Ensure CI passed
	- Merge `main` back into `dev` to keep in sync

