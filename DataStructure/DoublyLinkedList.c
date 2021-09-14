#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	struct ListNode* leftNode;
	char* data[10];
	struct ListNode* rightNode;
}listNode;

typedef struct {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void) {
	linkedList_h* DL;

	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;

	return DL;
}

void insertNode(linkedList_h* DL, listNode* pre, char* x) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	if (DL->head == NULL) {
		newNode->rightNode = NULL;
		newNode->leftNode = NULL;
		DL->head = newNode;
	}
	else {
		newNode->rightNode = pre->rightNode;
		pre->rightNode = newNode;
		newNode->leftNode = pre;

		if (newNode->rightNode != NULL) {
			newNode->rightNode->leftNode = newNode;
		}
	}
}

void deleteNode(linkedList_h* DL, listNode* oldNode) {
	if (DL->head == NULL) {
		return;
	}
	else if (oldNode == NULL) {
		return;
	}
	else {
		oldNode->leftNode->rightNode = oldNode->rightNode;
		oldNode->rightNode->leftNode = oldNode->leftNode;

		free(oldNode);
	}
}