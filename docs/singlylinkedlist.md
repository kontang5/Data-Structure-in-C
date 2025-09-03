# Singly Linked List

This API provides implementation of a singly linked list.

## Data Structure

```c
typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct SinglyLinkedList {
	Node *head;            
	Node *tail;
} SinglyLinkedList;
```

## Functions

### Memory Management

1. `void sll_clear(SinglyLinkedList *list)`

Free all nodes in the list.
- Parameter
	- `list`: Pointer to the singly linked list
- Time Complexity: **O(n)**

### Capacity

1. `size_t sll_size(SinglyLinkedList *list)`

Returns the number of elements in the list.
- Parameter
	- `list`: Pointer to the singly linked list
- Return: `size_t`
	- Number of nodes in the list
- Time Complexity: **O(n)**

2. `bool sll_is_empty(SinglyLinkedList *list)`

Check whether the list is empty.
- Parameter
	- `list`: Pointer to the singly linked list
- Return: `bool`
	- `true`: list is empty
	- `false`: list is not empty
- Time Complexity: **O(1)**

### Search

1. `int sll_get(SinglyLinkedList *list, size_t index)`

Retrieves the value stored at the given index.
- Parameter
	- `list`: Pointer to the singly linked list
	- `index`: Zero-based index of the element
- Return: `int`
	- Value at the given index
	- `-1`: index out of bounds
- Time Complexity: **O(n)**

2. `int sll_find(SinglyLinkedList *list, int value)`

Searches for the first occurrence of a value in the list.
- Parameter
	- `list`: Pointer to the singly linked list
	- `value`: Value to search for
- Return: `int`
	-Zero-based index of the value
	- `-1`: not found
- Time Complexity: **O(n)**

### Insertion

1. `void sll_append(SinglyLinkedList *list, int value)`

Adds a new node with the given value at the end of the list.
- Parameter
	- `list`: Pointer to the singly linked list
	- `value`: Value to insert
- Time Complexity: **O(1)**

2. `void sll_prepend(SinglyLinkedList *list, int value)`

Adds a new node with the given value at the beginning of the list.
- Parameter
	- `list`: Pointer to the singly linked list
	- `value`: Value to insert
- Time Complexity: **O(1)**

### Deletion

1. `void sll_delete(SinglyLinkedList *list, int value)`

Removes the first occurrence of a node containing the specified value.
- Parameter
	- `list`: Pointer to the singly linked list
	- `value`: Value to delete
- Time Complexity: **O(n)**


### Utility

1. `void sll_print(SinglyLinkedList *list)`

Prints the contents of the list
- Parameter:
	- `list`: Pointer to the singly linked list
- Output Format: `[val1, val2, ..., valn]`

