#include <stdio.h>
#include <malloc.h>

typedef char element;

typedef struct DequeNode {
	element data;
	struct DequeNode* leftLink;
	struct DequeNode* rightLink;
}DequeNode;

typedef struct {
	DequeNode* front;
	DequeNode* rear;
}DequeType;

DequeNode* createDeque() {
	DequeType* DQ;

	DQ = (DequeType*)malloc(sizeof(DequeType));
	DQ->front = NULL;
	DQ->rear = NULL;

	return DQ;
}

int isEmpty(DequeType* DQ) {
	if (DQ->front == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int insertFront(DequeType* DQ, element elem) {
	DequeNode* newNode = (DequeNode*)malloc(sizeof(DequeNode));

	newNode->data = elem;

	if (DQ->front == NULL) {
		DQ->front = newNode;
		DQ->rear = newNode;

		newNode->rightLink = NULL;
		newNode->leftLink = NULL;
	}
	else {
		DQ->front->leftLink = newNode;

		newNode->rightLink = DQ->front;
		newNode->leftLink = NULL;

		DQ->front = newNode;
	}
}

void insertRear(DequeType* DQ, element elem) {
	DequeNode* newNode = (DequeNode*)malloc(sizeof(DequeNode));

	newNode->data = elem;

	if (DQ->rear == NULL) {
		DQ->front = newNode;
		DQ->rear = newNode;

		newNode->rightLink = NULL;
		newNode->leftLink = NULL;
	}
	else {
		DQ->rear->rightLink = newNode;

		newNode->rightLink = NULL;
		newNode->leftLink = DQ->rear;

		DQ->rear = newNode;
	}
}

void deleteFront(DequeType* DQ) {
	DequeNode* oldNode = DQ->front;
	
	if (isEmpty(DQ)) {
		return 0;
	}
	else {
		if (DQ->front->rightLink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->front = DQ->front->rightLink;
			DQ->front->leftLink = NULL;
		}

		free(oldNode);

		return 0;
	}
}

element deleteRear(DequeType* DQ) {
	DequeNode* oldNode = DQ->rear;

	if (isEmpty(DQ)) {
		return 0;
	}
	else {
		if (DQ->rear->leftLink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->leftLink;
			DQ->rear->rightLink = NULL;
		}

		free(oldNode);

		return 0;
	}
}

element peekFront(DequeType* DQ) {
	element elem;

	if (isEmpty(DQ)) {
		return 0;
	}
	else {
		return elem = DQ->front->data;
	}
}

element peekRear(DequeType* DQ) {
	element elem;

	if (isEmpty(DQ)) {
		return 0;
	}
	else {
		return elem = DQ->rear->data;
	}
}