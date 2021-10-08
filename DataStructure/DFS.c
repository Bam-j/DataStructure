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
	graphNode* adjacentListHeadPointer[MAX_VERTEX];
	int visitedNode[MAX_VERTEX];
}graphType;

typedef int element;

typedef struct stackNode {
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;

int isEmpty() {
	if (top == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(element elem) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

	temp->data = elem;
	temp->link = top;
	top = temp;
}

element pop() {
	element elem;
	stackNode* temp = top;

	if (top == NULL) {
		return 0;
	}
	else {
		top = temp->link;

		free(temp);

		return elem;
	}
}

void createGraph(graphType* g) {
	g->n = 0;

	for (int v = 0; v < MAX_VERTEX; v++) {
		g->visitedNode[v] = FALSE;
		g->adjacentListHeadPointer[v] = NULL;
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

void DepthFirstSearch(graphType* g, int v) {
	graphNode* currentNode;

	top = NULL;

	push(v);

	g->visitedNode[v] = TRUE;

	while (!isEmpty()) {
		v = pop();
		currentNode = g->adjacentListHeadPointer[v];

		while (currentNode) {
			if (!g->visitedNode[currentNode->vertex]) {
				if (isEmpty()) {
					push(v);
				}

				push(currentNode->vertex);
				g->visitedNode[currentNode->vertex] = TRUE;
				v = currentNode->vertex;
				currentNode = g->adjacentListHeadPointer[v];
			}
			else {
				currentNode = currentNode->link;
			}
		}
	}
}