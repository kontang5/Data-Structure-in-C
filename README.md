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

## Guidelines

### Naming Conventions

- Test files: Prefix with `test_` (e.g., test\_list.c).
- Structs: Use `PascalCase`
- Functions: Use `snake_case` with the data structure name as prefix (e.g., `stack_push()`)

### Branch Strategy

- `main`: Stable version
- `dev`: Testing, debugging, experiments
- `feature/`: Implementation or improvement
- `hotfix/`: Urgent fixes

### Commit Message Prefix

- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation update
- `refactor`: Code refactoring
- `test`: tests
- `chore`: Other maintenance tasks

