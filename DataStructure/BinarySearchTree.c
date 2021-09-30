#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct BinarySearchTreeNode {
	int key;
	struct binarySearchTreeNode* leftNode;
	struct binarySearchTreeNode* rightNode;
} binarySearchTreeNode;

binarySearchTreeNode* insertNode(binarySearchTreeNode* ptr, int x) {
	binarySearchTreeNode* newNode;

	if (ptr == NULL) {
		newNode = (binarySearchTreeNode*)malloc(sizeof(binarySearchTreeNode));

		newNode->key = x;
		newNode->leftNode = NULL;
		newNode->rightNode = NULL;

		return newNode;
	}
	else if (x < ptr->key) {
		ptr->leftNode = insertNode(ptr->leftNode, x);

	}
	else if (x > ptr->key) {
		ptr->rightNode = insertNode(ptr->rightNode, x);
	}

	return ptr;
}

binarySearchTreeNode* searchNode(binarySearchTreeNode* root, int x) {
	binarySearchTreeNode* ptr;

	ptr = root;

	while (ptr != NULL) {
		if (x < ptr->key) {
			ptr = ptr->leftNode;
		}
		else if (x > ptr->key) {
			ptr = ptr->rightNode;
		}
		else if (x == ptr->key) {
			return ptr;
		}
	}
	//만약 while문 내에서 ptr이 반환되지 않는다면 탐색은 실패(찾는 데이터가 트리 내에 없음)
	return ptr;
}

void deleteNode(binarySearchTreeNode* root, int key) {
	binarySearchTreeNode* parentNode, * ptr, * succNode, * succParentNode, * childNode;

	parentNode = NULL;
	ptr = root;

	while ((ptr != NULL) && (ptr->key != key)) {
		parentNode = ptr;

		if (key < ptr->key) {
			ptr = ptr->leftNode;
		}
		else {
			ptr = ptr->key;
		}
	}

	if (ptr == NULL) {
		return;
	}

	if ((ptr->leftNode == NULL) && (ptr->rightNode == NULL)) {
		if (parentNode != NULL) {
			if (parentNode->leftNode == ptr) {
				parentNode->leftNode = NULL;
			}
			else {
				parentNode->rightNode = NULL;
			}
		}
		else {
			root = NULL;
		}
	}
	else if ((ptr->leftNode == NULL) || (ptr->rightNode == NULL)) {
		if (ptr->leftNode != NULL) {
			childNode = ptr->leftNode;
		}
		else {
			childNode = ptr->rightNode;
		}

		if (parentNode != NULL) {
			if (parentNode->leftNode == ptr) {
				parentNode->leftNode = childNode;
			}
			else {
				parentNode->rightNode = childNode;
			}
		}
		else {
			root = childNode;
		}
	}
	else {
		succParentNode = ptr;
		succNode = ptr->leftNode;

		while (succNode->rightNode != NULL) {
			succParentNode = succNode;
			succNode = ptr->rightNode;
		}

		if (succParentNode->leftNode == succNode) {
			succParentNode->leftNode = succNode->leftNode;
		}
		else {
			succParentNode->rightNode = succNode->leftNode;
		}

		ptr->key = succNode->key;
		ptr = succNode;
	}

	free(ptr);
}