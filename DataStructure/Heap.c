#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
	int heap[MAX];
	int heapSize;
}heapType;

heapType* createHeap() {
	heapType* h = (heapType*)malloc(sizeof(heapType));

	h->heapSize = 0;

	return h;
}

void insertHeap(heapType* h, int elem) {
	h->heapSize = h->heapSize + 1;

	int i = h->heapSize;

	while ((i != 1) && (elem > h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	h->heap[i] = elem;
}

void deleteHeap(heapType* h) {
	int parent, child, temp;

	temp = h->heap[h->heapSize];
	h->heapSize = h->heapSize - 1;

	parent = 1;
	child = 2;

	while (child <= h->heapSize) {
		if ((child < h->heapSize) && (h->heap[child] < h->heap[child + 1])) {
			child++;
		}

		if (temp >= h->heap[child]) {
			break;
		}
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}
	}

	h->heap[parent] = temp;
}