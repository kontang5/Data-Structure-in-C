#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @struct Node
 * @brief Represents a node in a singly linked list.
 */
typedef struct Node {
    int data;           //< Value stored in the node
    struct Node *next;  //< Pointer to the next node
} Node;

/**
 * @struct SinglyLinkedList
 * @brief Represents a singly linked list with a dummy head node.
 */
typedef struct {
    Node *head;         //< Dummy head node to simplify list operations
    Node *tail;         //< Pointer to the last node in the list
    size_t size;        //< Number of elements in the list
} SinglyLinkedList;

/**
 * @brief Initializes the list.
 * @param list Pointer to the list to initialize.
 */
void sll_init(SinglyLinkedList *list);

/**
 * @brief Removes all elements from the list.
 * @param list Pointer to the list to clear.
 */
void sll_clear(SinglyLinkedList *list);

/**
 * @brief Free all memory allocated by the list.
 * @param list Pointer to the list to free.
 */
void sll_free(SinglyLinkedList *list);

/**
 * @brief Returns the number of elements in the list.
 * @param list Pointer to the list.
 * @return Number of elements in the list.
 */
size_t sll_size(SinglyLinkedList *list);

/**
 * @brief Checks if the list is empty.
 * @param list Pointer to the list.
 * @return true if the list is empty, false otherwise.
 */
bool sll_is_empty(SinglyLinkedList *list);

/**
 * @brief Gets the value at a specific index in the list.
 * @param list Pointer to the list.
 * @param index Index of the element to return.
 * @return Value at the specified index.
 * @note Index must be less than the list size.
 * @warning Behavior is undefined if index is out of bounds.
 */
int sll_get(SinglyLinkedList *list, size_t index);

/**
 * @brief Gets the value of the first element in the list.
 * @param list Pointer to the list.
 * @return Value of the first element
 * @Warning Calling on an empty list leads to undefined behavior.
 */
int sll_front(SinglyLinkedList *list);

/**
 * @brief Gets the value of the last element in the list.
 * @param list Pointer to the list.
 * @return Value of the last element
 * @Warning Calling on an empty list leads to undefined behavior.
 */
int sll_back(SinglyLinkedList *list);

/**
 * @brief Finds the index of the first occurrence of a value in the list.
 * @param list Pointer to the list.
 * @param value Value to search for.
 * @return Index of the value, or -1 if not found.
 * @note The list is searched from the front to the back.
 * @warning Behavior is undefined if the list is empty.
 */
int sll_find(SinglyLinkedList *list, int value);

/**
 * @brief Appends a value to the end of the list.
 * @param list Pointer to the list.
 * @param value Value to append.
 * @note Index must be less than the list size.
 */
void sll_append(SinglyLinkedList *list, int value);

/**
 * @brief Prepends a value to the front of the list.
 * @param list Pointer to the list.
 * @param value Value to prepend.
 * @note Index must be less than the list size.
 */
void sll_prepend(SinglyLinkedList *list, int value);

/**
 * @brief Deletes the first occurrence of a value in the list.
 * @param list Pointer to the list.
 * @param value Value to delete.
 * @note Index must be less than the list size.
 */
void sll_delete(SinglyLinkedList *list, int value);

/**
 * @brief Prints all elements in the list.
 * @param list Pointer to the list.
 */
void sll_print(SinglyLinkedList *list);

#endif
