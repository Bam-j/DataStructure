#include <stdio.h>
#include <malloc.h>

typedef char element;

typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode* front, * rear;
}LinkedQueueType;

LinkedQueueType* createLinkedQueue() {
	LinkedQueueType* LQ;

	LQ = (LinkedQueueType*)malloc(sizeof(LinkedQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;

	return LQ;
}

int isEmpty(LinkedQueueType* LQ) {
	if (LQ->front == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void enQueue(LinkedQueueType* LQ, element elem) {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));

	newNode->data = elem;
	newNode->link = NULL;

	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

element deQueue(LinkedQueueType* LQ) {
	QueueNode* oldNode = LQ->front;

	if (isEmpty(LQ)) {
		return 0;
	}
	else {
		LQ->front = LQ->front->link;

		if (LQ->front == NULL) {
			LQ->rear = NULL;
		}

		free(oldNode);
	}
}

element peek(LinkedQueueType* LQ) {
	element elem;

	if (isEmpty(LQ)) {
		return 0;
	}
	else {
		elem = LQ->front->data;

		return elem;
	}
}