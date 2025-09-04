#include <stdio.h>
#include <assert.h>
#include "singlylinkedlist.h"

int main() {

	// Initialize as empty
	SinglyLinkedList list;
	sll_init(&list);
	assert(sll_is_empty(&list));
	assert(sll_size(&list) == 0);
	sll_print(&list);

	// Append
    sll_append(&list, 3);
	sll_append(&list, 5);
	sll_append(&list, 7);
	sll_print(&list);
	assert(!sll_is_empty(&list));
	assert(sll_size(&list) == 3);
	assert(sll_get(&list, 0) == 3);
	assert(sll_front(&list) == 3);
	assert(sll_get(&list, 1) == 5);
	assert(sll_back(&list) == 7);
	assert(sll_get(&list, 2) == 7);

	// Prepend
	sll_prepend(&list, 2);
	sll_print(&list);
	assert(sll_get(&list, 0) == 2);
	assert(sll_size(&list) == 4);

	// Find
	assert(sll_find(&list, 5) == 2);
	assert(sll_find(&list, 0) == -1);

	// Delete
	sll_delete(&list, 5);
	sll_print(&list);
	assert(sll_find(&list, 5) == -1);
	assert(sll_size(&list) == 3);

	// Clear
	sll_clear(&list);
	sll_print(&list);
	assert(sll_is_empty(&list));
	assert(sll_size(&list) == 0);

	printf("Complete SinglyLinkedList\n");
}

