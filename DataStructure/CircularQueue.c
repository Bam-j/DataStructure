#include <stdio.h>
#include <stdlib.h>

#define CIRCULAR_QUEUE_SIZE 5

typedef char element;

typedef struct {
	element queue[CIRCULAR_QUEUE_SIZE];
	int front;
	int rear;
}QueueType;

QueueType* createQueue() {
	QueueType* CQ;

	CQ = (QueueType*)malloc(sizeof(QueueType));
	CQ->front = 0;
	CQ->rear = 0;

	return CQ;
}

int isEmpty(QueueType* CQ) {
	if (CQ->front == CQ->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull(QueueType* CQ) {
	if ((CQ->rear + 1) % CIRCULAR_QUEUE_SIZE == CQ->front) {
		return 1;
	}
	else {
		return 0;
	}
}

void enQueue(QueueType* CQ, element elem) {
	if (isFull(CQ)) {
		return;
	}
	else {
		CQ->rear = (CQ->rear + 1) % CIRCULAR_QUEUE_SIZE;
		CQ->queue[CQ->rear] = elem;
	}
}

void deQueue(QueueType* CQ) {
	if (isEmpty(CQ)) {
		exit(1);
	}
	else {
		CQ->front = (CQ->front + 1) % CIRCULAR_QUEUE_SIZE;
	}
}

element peek(QueueType* CQ) {
	if (isEmpty(CQ)) {
		exit(1);
	}
	else {
		return CQ->queue[CQ->front + 1] % CIRCULAR_QUEUE_SIZE;
	}
}