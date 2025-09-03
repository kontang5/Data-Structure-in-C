#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stddef.h>
#include <stdbool.h>

// Definition
typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	Node *tail;
} SinglyLinkedList;

// Memory Management
void sll_clear(SinglyLinkedList *list);

// Capacity
size_t sll_size(SinglyLinkedList *list);
bool sll_is_empty(SinglyLinkedList *list);

// search
int sll_get(SinglyLinkedList *list, size_t index);
int sll_find(SinglyLinkedList *list, int value);

// Insertion
void sll_append(SinglyLinkedList *list, int value);
void sll_prepend(SinglyLinkedList *list, int value);

// Deletion
void sll_delete(SinglyLinkedList *list, int value);

// Print
void sll_print(SinglyLinkedList *list);

#endif
