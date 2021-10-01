#include <stdio.h>
#include <stdlib.h>

typedef struct avlTreeNode {
	int key;
	struct avlTreeNode* leftNode;
	struct avlTreeNode* rightNode;
}avlTreeNode;

avlTreeNode* LL_rotate(avlTreeNode* parent) {
	avlTreeNode* child = parent->leftNode;

	parent->leftNode = child->rightNode;
	child->rightNode = parent;

	return child;
}

avlTreeNode* RR_rotate(avlTreeNode* parent) {
	avlTreeNode* child = parent->rightNode;

	parent->rightNode = child->leftNode;
	child->leftNode = parent;

	return child;
}

avlTreeNode* LR_rotate(avlTreeNode* parent) {
	avlTreeNode* child = parent->leftNode;

	parent->leftNode = RR_rotate(child);

	return LL_rotate(parent);
}

avlTreeNode* RL_rotate(avlTreeNode* parent) {
	avlTreeNode* child = parent->rightNode;

	parent->rightNode = LL_rotate(child);

	return RR_rotate(parent);
}

int getHeightOfSubTree(avlTreeNode* ptr) {
	int height = 0;

	if (ptr != NULL) {
		height = MAX(getHeightOfSubTree(ptr->leftNode), getHeightOfSubTree(ptr->rightNode)) + 1;
	}

	return height;
}

int getBalanceFactor(avlTreeNode* ptr) {
	if (ptr == NULL) {
		return 0;
	}

	return getHeightOfSubTree(ptr->leftNode) - getHeightOfSubTree(ptr->rightNode);
}

avlTreeNode* rebalanceTree(avlTreeNode** ptr) {
	int balanceFactor = getBalanceFactor(*ptr);

	if (balanceFactor > 1) {
		if (getBalanceFactor((*ptr)->leftNode) > 0) {
			*ptr = LL_rotate(*ptr);
		}
		else {
			*ptr = LR_rotate(*ptr);
		}
	}
	else if (balanceFactor < -1) {
		if (getBalanceFactor((*ptr)->rightNode) < 0) {
			*ptr = RR_rotate(*ptr);
		}
		else {
			*ptr = RL_rotate(*ptr);
		}
	}
	return *ptr;
}