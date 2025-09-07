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
make atest TEST_NAME=test_target
```
> Replace target with the name of the test you want

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

1. Arange
2. Act
3. Assert
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

### Versioning

Semantic versioning (e.g., 0.1.2)
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
	- Merge commit with simple title
3. `hotfix`
	- Open a Pull Request targeting the `main` branch
	- Ensure CI passed
	- `Cherry-pick` the commit from `main` into `dev`

