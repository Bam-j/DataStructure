#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef int element;

element stack[STACK_SIZE];

int top = -1;

int isStackEmpty() {
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int isStackFull() {
	if (top == STACK_SIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(element elem) {
	if (isStackFull()) {
		return;
	}
	else {
		stack[++top] = elem;
	}
}

void pop() {
	if (isStackEmpty()) {
		return 0;
	}
	else {
		return stack[top--];
	}
}

element peek() {
	if (isStackEmpty()) {
		exit(1);
	}
	else {
		return stack[top];
	}
}