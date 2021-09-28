#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct BinaryTreeNode {
	struct BinaryTreeNode* leftNode;
	element data;
	struct BinaryTreeNode* rightNode;
}binaryTreeNode;

binaryTreeNode* createBinaryTree(void) {
	binaryTreeNode* BT;

	BT = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
	BT->leftNode = NULL;
	BT->rightNode = NULL;

	return BT;
}

void makeLeftSubTree(binaryTreeNode* current, binaryTreeNode* sub) {
	if (current->leftNode != NULL) {
		free(current->leftNode);
	}

	current->leftNode = sub;
}

void makeRightSubTree(binaryTreeNode* current, binaryTreeNode* sub) {
	if (current->rightNode != NULL) {
		free(current->rightNode);
	}

	current->rightNode = sub;
}

void setData(binaryTreeNode* BT, element elem) {
	BT->data = elem;
}

element getData(binaryTreeNode* BT) {
	return BT->data;
}

binaryTreeNode* getLeftSubTree(binaryTreeNode* BT) {
	return BT->leftNode;
}

binaryTreeNode* getRightSubTree(binaryTreeNode* BT) {
	return BT->rightNode;
}

void preorder(binaryTreeNode* BT) {
	if (BT) {
		//���� ��� ���� ��ġ(���� ��ȸ)
		preorder(BT->leftNode);
		preorder(BT->rightNode);
	}
}

void inorder(binaryTreeNode* BT) {
	if (BT) {
		inorder(BT->leftNode);
		//���� ��� ���� ��ġ(���� ��ȸ)
		inorder(BT->rightNode);
	}
}

void postorder(binaryTreeNode* BT) {
	if (BT) {
		postorder(BT->leftNode);
		postorder(BT->rightNode);
		//���� ��� ���� ��ġ(���� ��ȸ)
	}
}