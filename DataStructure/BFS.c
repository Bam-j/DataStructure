#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	int n;
	graphNode* adjacentListHeadPtr[MAX_VERTEX];
	int visitedNode[MAX_VERTEX];
}graphType;

typedef int element;

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
	int elem;
	QueueNode* oldNode = LQ->front;

	if (isEmpty(LQ)) {
		return 0;
	}
	else {
		elem = oldNode->data;
		LQ->front = LQ->front->link;

		if (LQ->front == NULL) {
			LQ->rear = NULL;
		}

		free(oldNode);

		return elem;
	}
}

void createGraph(graphType* g) {
	g->n = 0;

	for (int i = 0; i < MAX_VERTEX; i++) {
		g->adjacentListHeadPtr[i] = NULL;
	}
}

void insertVertex(graphType* g, int v) {
	if (g->n + 1 > MAX_VERTEX) {
		return;
	}

	g->n++;
}

void insertEdge(graphType* g, int tail, int head) {
	graphNode* node;

	if ((tail >= g->n) || (head >= g->n)) {
		return;
	}

	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = head;
	node->link = g->adjacentListHeadPtr[tail];

	g->adjacentListHeadPtr[tail] = node;
}

void BreadthFirstSearch(graphType* g, int v) {
	graphNode* currentNode;
	QueueNode* Q;

	Q = createLinkedQueue();
	g->visitedNode[v] = TRUE;

	enQueue(Q, v);

	while (!isEmpty(Q)) {
		v = deQueue(Q);

		for (currentNode = g->adjacentListHeadPtr[v]; currentNode; currentNode = currentNode->link) {
			if (!g->visitedNode[currentNode->vertex]) {
				g->visitedNode[currentNode->vertex] = TRUE;
				
				enQueue(Q, currentNode->vertex);
			}
		}
	}
}