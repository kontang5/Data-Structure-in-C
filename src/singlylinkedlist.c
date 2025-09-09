#include <stdio.h>
#include <stdlib.h>
#include "singlylinkedlist.h"

Node* node_init(int value) {
	Node *node = malloc(sizeof(*node));
	if (!node) return NULL;

	node->data = value;
	node->next = NULL;
	return node;
}

void node_free(Node *node) {
	free(node);
}

SinglyLinkedList *sll_init(void) {
	SinglyLinkedList *list = malloc(sizeof(*list));
	if (!list) return NULL;

	Node* head = node_init(0);
	if (!head) {
		free(list);
		return NULL;
	}

	list->head = head;
	list->tail = head;
	list->size = 0;
	return list;
}

void sll_clear(SinglyLinkedList *list) {
	if (!list) return;

	Node *current = list->head->next;
	while (current) {
		Node *next = current->next;
		node_free(current);
		current = next;
	}
	list->head->next = NULL;
	list->tail = list->head;
	list->size = 0;
}

void sll_free(SinglyLinkedList *list) {
	if (!list) return;

	sll_clear(list);
	node_free(list->head);
	free(list);
}

bool sll_prepend(SinglyLinkedList *list, int value) {
	if (!list) return false;

	Node *new = node_init(value);
	if (!new) return false;

	new->next = list->head->next;
	list->head->next = new;
	if (list->tail == list->head) list->tail = new;
	list->size++;
	return true;
}

bool sll_append(SinglyLinkedList *list, int value) {
	if(!list) return false;

	Node *new = node_init(value);
	if (!new) return false;

	list->tail->next = new;
	list->tail = new;
	list->size++;
	return true;
}

bool sll_insert_at(SinglyLinkedList *list, size_t index, int value) {
	if (!list) return false;

	if (index > list->size) return false;

	Node *prev = list->head;
	for (size_t i = 0; i < index; i++) prev = prev->next;
	Node *new = node_init(value);
	if (!new) return false;

	new->next = prev->next;
	prev->next = new;
	if (prev == list->tail) list->tail = new;
	list->size++;

	return true;
}

bool sll_delete_at(SinglyLinkedList *list, size_t index) {
	if (!list) return false;

	if (index >= list->size) return false;

	Node *prev = list->head;
	for (size_t i = 0; i < index; i++) prev = prev->next;
	Node *target = prev->next;
	prev->next = target->next;
	if (target == list->tail) list->tail = prev;
	node_free(target);
	list->size--;
	
	return true;
}

bool sll_delete_value(SinglyLinkedList *list, int value) {
	if (!list) return false;

	Node *prev = list->head;
	Node *current = list->head->next;
	while (current) {
		if (current->data == value) {
			prev->next = current->next;
			if (current == list->tail) list->tail = prev;
			node_free(current);
			list->size--;
			return true;
		}
		prev = current;
		current = prev->next;
	}
	return false;
}

bool sll_get(SinglyLinkedList *list, size_t index, int *output) {
	if (!list) return false;

	if (index >= list->size) return false;

	if (!output) return false;

	Node *current = list->head->next;
	for (size_t i = 0; i < index; i++) current = current->next;
	*output = current->data;
	return true;
}

int sll_index_of(SinglyLinkedList *list, int value) {
	if (!list) return -1;

	Node *current = list->head->next;
	size_t index = 0;
	while (current) {
		if (current->data == value) return (int)index;
		
		current = current->next;
		index++;
	}
	return -1;
}

bool sll_contains(SinglyLinkedList *list, int value) {
	return sll_index_of(list, value) != -1;
}

size_t sll_size(SinglyLinkedList *list) {
	return list ? list->size : 0;
}

bool sll_is_empty(SinglyLinkedList *list) {
	return list ? list->size == 0 : true;
}

void sll_print(SinglyLinkedList *list) {
	if (!list) return;

	Node *current = list->head->next;
	printf("[");
	while (current) {
		printf("%d", current->data);
		if (current->next) printf(", ");
		current = current->next;
	}
	printf("]\n");
}

void sll_reverse(SinglyLinkedList *list) {
	if (!list) return;

	if (list->size == 1) return;

	Node *prev = NULL;
	Node *current = list->head->next;
	Node *next = NULL;
	list->tail = current;
	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list->head->next = prev;
}

void sll_sort(SinglyLinkedList *list) {
	if (!list) return;

	if (list->size == 1) return;

	Node *last = NULL;

	while (last != list->head->next) {
		Node *prev = list->head;
		Node *current = list->head->next;
		while (current->next != last) {
			Node *next = current->next;
			if (current->data > next->data) {
				current->next = next->next;
				next->next = current;
				prev->next = next;
				prev = next;
			} else {
				prev = current;
				current = current->next;
			}
		}
		last = current;
	}
	Node *temp = list->head;
	while (temp->next) temp= temp->next;
	list->tail = temp;
}

SinglyLinkedList *sll_clone(SinglyLinkedList *list) {
	if (!list) return NULL;

	SinglyLinkedList *new = sll_init();
	if (!new) return NULL;

	Node *current = list->head->next;
	while (current) {
		if (!sll_append(new, current->data)) {
			sll_free(new);
			return NULL;
		}
		current = current->next;
	}
	return new;
}

void sll_for_each(SinglyLinkedList *list, void(*func)(int, void *), void *ctx) {
	if (!list) return;
	
	if (!func) return;

	Node *current = list->head->next;
	while (current) {
		func(current->data, ctx);
		current = current->next;
	}
}

