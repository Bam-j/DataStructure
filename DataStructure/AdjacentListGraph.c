#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 10

typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	int n;
	graphNode* adjacentListHeadPointer[MAX_VERTEX];
}graphType;

void createGraph(graphType* g) {
	g->n = 0;

	for (int i = 0; i < MAX_VERTEX; i++) {
		g->adjacentListHeadPointer[i] = NULL;
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
	node->link = g->adjacentListHeadPointer[tail];

	g->adjacentListHeadPointer[tail] = node;
}