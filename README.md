# Data Structure in C

**C library of data structures** for learning and personal projects.
Based on *C99*

## Features
1. LinkedList
	1. SinglyLinkedList

## How to Use

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
make atest TEST_NAME=target
```
> Replace the target with the name of the test you want

4. Clean build artifacts

```shell
make clean
```

## Project Structure

```
data-structure-in-c  
├── include/  
│   └── header files  
├── src/  
│   └── implementation files  
├── test/  
│   └── test files  
├── build/  
├── Makefile  
└── README.md  
```

## Project Guidelines

### Naming Conventions

- Structs: Use `PascalCase`
- Functions: Use `snake_case` with the data structure name as prefix (e.g., `stack_push()`)
- Test files: suffix with `_t` (e.g., list\_t.c).

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
/// @file addition.c
/// @brief Simple example demonstrating Doxygen comments.
///
///  This file provides basic add operations and a Point struct
/// to demonstrate Doxygen documentation in C.

#include <stdio.h>
#include <stdlib.h>

/// @struct Point
/// @brief Represents a 2D point.
typedef struct {
    int x; ///< X coordinate
    int y; ///< Y coordinate
} Point;

/// @brief Adds two integers.
/// @param a First integer.
/// @param b Second integer.
/// @return Sum of a and b.
int add(int a, int b) {
    return a + b;
}

/// @brief Main function demonstrating addition usage.
/// @return Exit status code.
int main(void) {
    Point p = {3, 4}; ///< Example point

    int x = 10, y = 5;

    printf("add(%d, %d) = %d\n", x, y, add(x, y));
    
    return 0;
}
```

### Versioning

#### Semantic versioning (e.g., 0.1.2)
- Major: Incompatible API changes
- Minor: Backward-compatible changes
- Patch: bugfixes, tiny update

## Repository Guidelines

### Commit Message Prefix

- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation update
- `refactor`: Code refactoring
- `test`: tests
- `chore`: Other maintenance tasks

### Branch Strategy

- `main`: Stable version
- `dev`: Testing, debugging, experiments
- `feature/`: Implementation or improvement
- `hotfix/`: Urgent fixes

### Merge Strategy

1. `feature` -> `dev`
	- Open a Pull Request targeting the `dev` branch
	- Ensure code review, automated tests, and CI checks if needed
	- Merge commit with its feature branch name
2. `dev` -> `main`
	- Open a Pull Request targeting the `main` branch
	- Review and confirm all tests passed.
	- Merge commit with a simple title
3. `hotfix`
	- Open a Pull Request targeting the `main` branch
	- Ensure CI passed
	- `Cherry-pick` the commit from `main` into `dev`

