#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "singlylinkedlist.h"

void sll_clear(SinglyLinkedList *list) {
	Node *current = list->head;
	while (current) {
		Node *temp = current;
		current = current->next;
		free(temp);
	}
	list->head = NULL;
	list->tail = NULL;	// Reset tail
}

size_t sll_size(SinglyLinkedList *list) {
	Node *current = list->head;
	size_t size = 0;
	
	while (current) {
		size++;
		current = current->next;
	}
	
	return size;
}

bool sll_is_empty(SinglyLinkedList *list) {
	return list->head == NULL;
}

int sll_get(SinglyLinkedList *list, size_t index) {
	Node *current = list->head;
	size_t i = 0;

	while (current) {
		if (i == index)
			return current->data;
		current = current->next;
		i++;
	}
	return -1;
}

int sll_find(SinglyLinkedList *list, int value) {
	Node *current = list->head;
	size_t i= 0;

	while (current) {
		if (current->data == value)
			return (int)i;
		current = current->next;
		i++;
	}
	return -1;
}

void sll_append(SinglyLinkedList *list, int value) {
	Node *new = (Node *)malloc(sizeof(Node));

	if (!new)
		return;

	new->data = value;
	new->next = NULL;

	if (!list->head) {
		list->head = new;
		list->tail = new;	// Update tail
		return;
	}
	list->tail->next = new;	// Append at tail
	list->tail = new;	// Update tail
}

void sll_prepend(SinglyLinkedList *list, int value) {
	Node *new = (Node *)malloc(sizeof(Node));

	if (!new)
		return;

	new->data = value;
	new->next = list->head;
	list->head = new;

	if (!list->tail)
		list->tail = new;
}

void sll_delete(SinglyLinkedList *list, int value) {

	if (!list->head)
		return;

	Node *current = list->head;
	Node *previous = NULL;

	while (current) {
		if (current->data == value) {
			if (previous) 
				previous->next = current->next;	
			else 
				list->head = current->next;
			if (current == list->tail)	// Update tail if last node deleted
				list->tail = previous;

			free(current);
			return;
		}
		previous = current;
		current = current->next;
	}
}

void sll_print(SinglyLinkedList *list) {
	Node *current = list->head;

	printf("[");
	while (current) {
		if (current->next)
			printf("%d, ", current->data);
		else
			printf("%d", current->data);

		current = current->next;
	}
	printf("]\n");
}
