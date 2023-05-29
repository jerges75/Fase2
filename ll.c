#define _CRT_SECURE_NO_WARNINGS
#include "ll.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ListElem addItemHead(ListElem head, void* data) {
	ListElem aux;

	if ((aux = (ListElem)malloc(sizeof(SListElem))) == NULL)
		return head;

	aux->data = data;
	aux->next = head;

	return aux;
}

ListElem addItemLastIterative(ListElem head, void* data) {
	ListElem aux, prev;

	aux = (ListElem)malloc(sizeof(SListElem));
	aux->data = data;
	aux->next = NULL;

	if (head == NULL) {
		return aux;
	}

	for (prev = head; prev->next != NULL; prev = prev->next)
		;

	prev->next = aux;

	return head;
}

void showListIterative(ListElem head, void (*show)(void* data)) {

	while (head != NULL) {
		show(head->data);
		head = head->next;
	}

}

ListElem removeItemIterative(ListElem head, void* data, int (*compare)(void* data1, void* data2)) {
	ListElem aux, prev;

	// List is empty
	if (head == NULL)
		return NULL;

	// Element to remove is on the head of the list
	if (compare(head->data, data) == 1) {
		aux = head->next;
		free(head);
		return aux;
	}

	// Element to remove is in the tail of the list
	for (prev = head; prev->next != NULL; prev = prev->next)
	{
		if (compare(prev->next->data, data) == 1) {
			aux = prev->next;
			prev->next = prev->next->next;
			free(aux);
			break;
		}
	}

	return head;
}

ListElem addItemOrderedIterative(ListElem head, void* data, int (*compare)(void* data1, void* data2)) {
	ListElem n, aux;

	n = (ListElem)malloc(sizeof(SListElem));
	n->data = data;
	n->next = NULL;

	if (head == NULL || compare(data, head->data) < 0) {
		n->next = head;
		return n;
	}

	for (aux = head; aux->next != NULL; aux = aux->next) {
		if (compare(data, aux->next->data) < 0) {
			n->next = aux->next;
			aux->next = n;
			return head;
		}
	}

	aux->next = n;
	return head;
}


