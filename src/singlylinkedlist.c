#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "singlylinkedlist.h"

void sll_init(SinglyLinkedList *list) {
	list->dummy = (Node *)malloc(sizeof(Node));
	if (!list->dummy)
		return;
	list->dummy->next = NULL;
	list->tail = NULL;
	list->size = 0;
}

void sll_clear(SinglyLinkedList *list) {
	Node *current = list->dummy->next;
	while (current) {
		Node *temp = current;
		current = current->next;
		free(temp);
	}
	list->dummy->next = NULL;
	list->tail = NULL;
	list->size = 0;
}

void sll_free(SinglyLinkedList *list) {
	if (!list->dummy)
		return;
	sll_clear(list);
	free(list->dummy);
	list->dummy = NULL;
	list->tail = NULL;
	list->size = 0;
}

size_t sll_size(SinglyLinkedList *list) {
	return list->size;
}

bool sll_is_empty(SinglyLinkedList *list) {
	return list->size == 0;
}

int sll_get(SinglyLinkedList *list, size_t index) {
	if (index >= list->size) 
		return -1;

	Node *current = list->dummy;
	for (size_t i = 0; i <= index; i++)
		current = current->next;
	return current->data;
}

int sll_front(SinglyLinkedList *list) {
	return (list->size == 0) ? -1 : list->dummy->next->data;
}

int sll_back(SinglyLinkedList *list) {
	return (list->size == 0) ? -1 : list->tail->data;
}

int sll_find(SinglyLinkedList *list, int value) {
	Node *current = list->dummy->next;
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

	if (!list->tail) {
		list->dummy->next = new;
	} else {
		list->tail->next = new;
	}
	list->tail = new;
	list->size++;
}

void sll_prepend(SinglyLinkedList *list, int value) {
	Node *new = (Node *)malloc(sizeof(Node));

	if (!new)
		return;

	new->data = value;
	new->next = list->dummy->next;
	list->dummy->next = new;

	if (!list->tail)
		list->tail = new;

	list->size++;
}

void sll_delete(SinglyLinkedList *list, int value) {
	Node *current = list->dummy;

	while (current->next) {
		if (current->next->data == value) {
			Node *target = current->next;
			current->next = target->next;
			if (target == list->tail)
				list->tail = (current == list->dummy) ? NULL : current;
			free(target);
			list->size--;
			return;
		}
		current = current->next;
	}
}

void sll_print(SinglyLinkedList *list) {
	Node *current = list->dummy->next;

	printf("[");
	while (current) {
		printf("%d", current->data);
		if (current->next)
			printf(", ");
		current = current->next;
	}
	printf("]\n");
}
