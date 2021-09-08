#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	char data[10];
	struct ListNode* link;
}listNode;

typedef struct {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void) {
	linkedList_h* CL;

	CL = (linkedList_h*)malloc(sizeof(linkedList_h));
	CL->head = NULL;

	return CL;
}

void insertFirstNode(linkedList_h* CL, char* x) {
	listNode* newNode, * temp;

	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	if (CL->head = NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		temp = CL->head;

		while (temp->link != CL->head) {
			temp = temp->link;
		}

		newNode->link = temp->link;
		temp->link = newNode;
		CL->head = newNode;
	}
}

void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	if (CL == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void deleteNode(linkedList_h* CL, listNode* oldNode) {
	listNode* pre;

	if (CL->head==NULL) {
		return;
	}

	if (CL->head->link == CL->head) {
		free(CL->head);
		CL->head = NULL;
		return;
	}
	else if (oldNode == NULL) {
		return;
	}
	else {
		pre = CL->head;

		while (pre->link != oldNode) {
			pre = pre->link;
		}

		pre->link = oldNode->link;

		if (oldNode == CL->head) {
			CL->head = oldNode->link;
		}

		free(oldNode);
	}
}

//Å½»ö
listNode* search(linkedList_h* CL, char* x) {
	listNode* temp;

	temp = CL->head;

	if (temp == NULL) {
		return NULL;
	}

	do {
		if (strcmp(temp->data, x) == 0) {
			return temp;
		}
		else {
			temp = temp->link;
		}
	} while (temp !=CL->head);

	return NULL;
}