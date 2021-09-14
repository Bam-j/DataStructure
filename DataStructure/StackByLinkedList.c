#include <stdio.h>
#include <stdlib.h>

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
	stackNode* temp = top;

	if (top == NULL) {
		return 0;
	}
	else {
		top = temp->link;

		free(temp);

		return 0;
	}
}

element peek() {
	if (top == NULL) {
		return 0;
	}
	else {
		return top->data;
	}
}