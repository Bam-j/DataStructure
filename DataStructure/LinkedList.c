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
	linkedList_h* L;

	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

void freeLinkedList_h(linkedList_h* L) {
	listNode* p;

	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void printList(linkedList_h* L) {
	listNode* p;

	printf("L= (");
	p = L->head;

	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;

		if (p != NULL) {
			printf(", ");
		}
	}
	printf("\n");
}

void insertFirst(linkedList_h* L, char* x) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

void insertMiddle(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	if (L == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}

	else if (pre == NULL) {
		L->head = newNode;
	}

	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertLast(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;

	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;

	if (L->head == NULL) {
		L->head = newNode;
		return;
	}

	temp = L->head;

	while (temp->link != NULL) {
		temp = temp->link;
	}

	temp->link = newNode;
	{

	}
}

void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;

	if (L->head == NULL) {
		return;
	}

	if (L->head->link == NULL) {
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (p == NULL) {
		return;
	}
	else {
		pre = L->head;

		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
	}
}

listNode* search(linkedList_h* L, char* x) {
	listNode* temp;

	temp = L->head;

	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) {
			return temp;
		}
		else {
			temp = temp->link;
		}
	}
	return temp;
}