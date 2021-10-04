#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 10

typedef struct graph {
	int n;
	int adjacentMatrix[MAX_VERTEX][MAX_VERTEX];
}graph;

void createGraph(graph* g) {
	g->n = 0;

	for (int i = 0; i < MAX_VERTEX; i++) {
		for (int j = 0; j < MAX_VERTEX; j++) {
			g->adjacentMatrix[i][j] = 0;
		}
	}
}

void insertVertex(graph* g, int v) {
	if (g->n + 1 > MAX_VERTEX) {
		return;
	}

	g->n++;
}

void insertEdge(graph* g, int tail, int head) {
	if ((tail >= g->n) || (head >= g->n)) {
		return;
	}

	g->adjacentMatrix[tail][head] = 1;
}