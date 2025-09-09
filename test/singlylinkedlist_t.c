#include <assert.h>
#include <stdio.h>
#include "singlylinkedlist.h"

// Helper

static void add_to_sum(int x, void *ctx) {
	int *sum = ctx;
	*sum += x;
}

// AAA TESTS FOR SINGLY LINKED LIST

void test_init_and_free() {
    // Arrange & Act
    SinglyLinkedList *list = sll_init();

    // Assert
    assert(list != NULL);
    assert(sll_is_empty(list));
    assert(sll_size(list) == 0);

    sll_free(list);
}

void test_node_init_and_free() {
    // Arrange & Act
    Node *n = node_init(42);

    // Assert
    assert(n != NULL);
    assert(n->data == 42);
    assert(n->next == NULL);

    node_free(n);
}

void test_append_and_get() {
    // Arrange
    SinglyLinkedList *list = sll_init();

    // Act
    assert(sll_append(list, 10));
    assert(sll_append(list, 20));
    assert(sll_append(list, 30));

    // Assert
    assert(sll_size(list) == 3);

    int value;
    assert(sll_get(list, 0, &value) && value == 10);
    assert(sll_get(list, 1, &value) && value == 20);
    assert(sll_get(list, 2, &value) && value == 30);

    sll_free(list);
}

void test_prepend() {
    // Arrange
    SinglyLinkedList *list = sll_init();

    // Act
    sll_prepend(list, 3);
    sll_prepend(list, 2);
    sll_prepend(list, 1);

    // Assert
    int value;
    assert(sll_get(list, 0, &value) && value == 1);
    assert(sll_get(list, 1, &value) && value == 2);
    assert(sll_get(list, 2, &value) && value == 3);

    sll_free(list);
}

void test_insert_at() {
    // Arrange
    SinglyLinkedList *list = sll_init();
    sll_append(list, 1);
    sll_append(list, 3);

    // Act
    bool inserted = sll_insert_at(list, 1, 2);

    // Assert
    assert(inserted);
    int value;
    assert(sll_get(list, 0, &value) && value == 1);
    assert(sll_get(list, 1, &value) && value == 2);
    assert(sll_get(list, 2, &value) && value == 3);

    sll_free(list);
}

void test_delete_at() {
    // Arrange
    SinglyLinkedList *list = sll_init();
    sll_append(list, 1);
    sll_append(list, 2);
    sll_append(list, 3);

    // Act
    bool deleted = sll_delete_at(list, 1);

    // Assert
    assert(deleted);
    assert(sll_size(list) == 2);

    int value;
    assert(sll_get(list, 0, &value) && value == 1);
    assert(sll_get(list, 1, &value) && value == 3);

    sll_free(list);
}

void test_delete_value() {
    // Arrange
    SinglyLinkedList *list = sll_init();
    sll_append(list, 5);
    sll_append(list, 6);
    sll_append(list, 7);

    // Act
    bool deleted = sll_delete_value(list, 6);

    // Assert
    assert(deleted);
    assert(sll_size(list) == 2);

    int value;
    assert(sll_get(list, 0, &value) && value == 5);
    assert(sll_get(list, 1, &value) && value == 7);

    sll_free(list);
}

void test_index_of_and_contains() {
    // Arrange
    SinglyLinkedList *list = sll_init();
    sll_append(list, 100);
    sll_append(list, 200);
    sll_append(list, 300);

    // Act & Assert
    assert(sll_index_of(list, 200) == 1);
    assert(sll_index_of(list, 999) == -1);
    assert(sll_contains(list, 300));
    assert(!sll_contains(list, 999));

    sll_free(list);
}

void test_reverse() {
    // Arrange
    SinglyLinkedList *list = sll_init();
    sll_append(list, 1);
    sll_append(list, 2);
    sll_append(list, 3);

    // Act
    sll_reverse(list);

    // Assert
    int value;
    assert(sll_get(list, 0, &value) && value == 3);
    assert(sll_get(list, 1, &value) && value == 2);
    assert(sll_get(list, 2, &value) && value == 1);

    sll_free(list);
}

void test_sort() {
    // Arrange
    SinglyLinkedList *list = sll_init();
    sll_append(list, 30);
    sll_append(list, 10);
    sll_append(list, 20);

    // Act
    sll_sort(list);

    // Assert
    int value;
    assert(sll_get(list, 0, &value) && value == 10);
    assert(sll_get(list, 1, &value) && value == 20);
    assert(sll_get(list, 2, &value) && value == 30);

    sll_free(list);
}

void test_clone() {
    // Arrange
    SinglyLinkedList *list = sll_init();
    sll_append(list, 1);
    sll_append(list, 2);

    // Act
    SinglyLinkedList *clone = sll_clone(list);

    // Assert
    assert(clone != NULL);
    assert(sll_size(clone) == 2);

    int value;
    assert(sll_get(clone, 0, &value) && value == 1);
    assert(sll_get(clone, 1, &value) && value == 2);

    sll_free(list);
    sll_free(clone);
}

void test_for_each() {
    // Arrange
    SinglyLinkedList *list = sll_init();
    sll_append(list, 1);
    sll_append(list, 2);
    sll_append(list, 3);

    int sum = 0;

    // Act
    sll_for_each(list, add_to_sum, &sum);

    // Assert
    assert(sum == 6);

    sll_free(list);
}

int main(void) {
    test_init_and_free();
    test_node_init_and_free();
    test_append_and_get();
    test_prepend();
    test_insert_at();
    test_delete_at();
    test_delete_value();
    test_index_of_and_contains();
    test_reverse();
    test_sort();
    test_clone();
    test_for_each();

    return 0;
}
