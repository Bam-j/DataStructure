#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

typedef char element;

typedef struct {
	element queue[QUEUE_SIZE];
	int front, rear;
}QueueType;

QueueType* createQueue() {
	QueueType* Q;

	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;

	return 0;
}

int isEmpty(QueueType* Q) {
	if (Q->front == Q->rear) {
		return 1;
	}

	return 0;
}

int isFull(QueueType* Q) {
	if (Q->rear == QUEUE_SIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void enQueue(QueueType* Q, element elem) {
	if (isFull(Q)) {
		return;
	}
	else {
		Q->rear++;
		Q->queue[Q->rear] = elem;
	}
}

void deQueue(QueueType* Q) {
	if (isEmpty(Q)) {
		return;
	}
	else {
		Q->front++;
	}
}

element peek(QueueType* Q) {
	if (isEmpty(Q)) {
		exit(1);
	}
	else {
		return Q->queue[Q->front + 1];
	}
}