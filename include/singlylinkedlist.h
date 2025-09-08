#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stddef.h>
#include <stdbool.h>

/// Represents a node in a singly linked list
typedef struct Node {
    int data;           ///< Value stored in the node
    struct Node *next;  ///< Pointer to the next node
} Node;

/// Represents a singly linked list with a dummy head node
typedef struct {
    Node *head;         ///< Dummy head node to simplify list operations
    Node *tail;         ///< Pointer to the last node in the list
    size_t size;        ///< Number of elements in the list
} SinglyLinkedList;

// Memory management functions

/// Create and initialize a new node
/// @param value Value to store in the node
/// @return Pointer to the newly created node, or NULL if allocation fails
Node *node_init(int value);

/// Free a node
/// @param node Pointer to the node to be freed
void node_free(Node *node);

/// Create and initialize a new empty singly linked list
/// @return Pointer to the newly created list, or NULL if allocation fails
SinglyLinkedList *sll_init(void);

/// Clear all nodes from the list but keep the list structure intact
/// @param list Pointer to the list
void sll_clear(SinglyLinkedList *list);

/// Free all nodes and the list structure itself
/// @param list Pointer to the singly linked list
void sll_free(SinglyLinkedList *list);

// Operations

/// Insert a value at the beginning of the list
/// @param list Pointer to the list
/// @param value Value to insert
/// @return true if successful, false if allocation fails
bool sll_prepend(SinglyLinkedList *list, int value);

/// Insert a value at the end of the list
/// @param list Pointer to the list
/// @param value Value to insert
/// @return true if successful, false if allocation fails
bool sll_append(SinglyLinkedList *list, int value);

/// Insert a value at a specific index
/// @param list Pointer to the list
/// @param index Position to insert at (0-based)
/// @param value Value to insert
/// @return true if successful, false if allocation fails or index is out of range
bool sll_insert_at(SinglyLinkedList *list, size_t index, int value);

/// Delete the node at a specific index
/// @param list Pointer to the list
/// @param index Index of the node to delete
/// @return true if successful, false if index is out of range
bool sll_delete_at(SinglyLinkedList *list, size_t index);

/// Delete the first node containing a specific value
/// @param list Pointer to the list
/// @param value Value to delete
/// @return true if a node was deleted, false if not found
bool sll_delete_value(SinglyLinkedList *list, int value);

/// Retrieve the value at a specific index
/// @param list Pointer to the list
/// @param index Index of the node (0-based)
/// @param out_value Pointer to store the retrieved value
/// @return true if successful, false if index is out of range
bool sll_get(SinglyLinkedList *list, size_t index, int *out_value);

/// Find the index of the first node containing a specific value
/// @param list Pointer to the list
/// @param value Value to search for
/// @return Index of the node, or -1 if not found
int sll_index_of(SinglyLinkedList *list, int value);

/// Check if the list contains a specific value
/// @param list Pointer to the list
/// @param value Value to search for
/// @return true if value exists, false otherwise
bool sll_contains(SinglyLinkedList *list, int value);

/// Get the number of elements in the list
/// @param list Pointer to the list
/// @return Number of elements
size_t sll_size(SinglyLinkedList *list);

/// Check if the list is empty
/// @param list Pointer to the list
/// @return true if empty, false otherwise
bool sll_is_empty(SinglyLinkedList *list);

/// Print the list to stdout
/// @param list Pointer to the list
void sll_print(SinglyLinkedList *list);

/// Reverse the list in-place
/// @param list Pointer to the list
void sll_reverse(SinglyLinkedList *list);

/// Sort the list in ascending order
/// @param list Pointer to the list
void sll_sort(SinglyLinkedList *list);

/// Create a copy of the list
/// @param list Pointer to the list
/// @return Pointer to the cloned list, or NULL if allocation fails
SinglyLinkedList *sll_clone(SinglyLinkedList *list);

/// Iterate over the list and call a function for each node
/// @param list Pointer to the list
/// @param func Function to call for each node
/// @param ctx Pointer to arbitrary user data
void sll_for_each(SinglyLinkedList *list, void(*func)(int, void *), void *ctx);

#endif
