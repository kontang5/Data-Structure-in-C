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
}

size_t sll_size(SinglyLinkedList *list) {
	Node *current = list->dummy->next;
	size_t size = 0;
	
	while (current) {
		size++;
		current = current->next;
	}
	
	return size;
}

bool sll_is_empty(SinglyLinkedList *list) {
	return list->dummy->next == NULL;
}

int sll_get(SinglyLinkedList *list, size_t index) {
	Node *current = list->dummy->next;
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
		list->tail = new;
	} else {
		list->tail->next = new;
		list->tail = new;
	}
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
			return;
		}
		current = current->next;
	}
}

void sll_print(SinglyLinkedList *list) {
	Node *current = list->dummy->next;

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
