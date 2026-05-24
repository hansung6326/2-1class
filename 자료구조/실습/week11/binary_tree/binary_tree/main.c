#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int findMin(TreeNode* root) {
	int min = root->data;

	if (root->left != NULL) {
		int leftMin = findMin(root->left);
		if (leftMin < min)
			min = leftMin;
	}

	if (root->right != NULL) {
		int rightMin = findMin(root->right);
		if (rightMin < min)
			min = rightMin;
	}

	return min;
}

int findMax(TreeNode* root) {
	int max = root->data;

	if (root->left != NULL) {
		int leftMax = findMax(root->left);
		if (leftMax > max)
			max = leftMax;
	}

	if (root->right != NULL) {
		int rightMax = findMax(root->right);
		if (rightMax > max)
			max = rightMax;
	}

	return max;
}

int main(void)
{
	TreeNode* n1, * n2, * n3;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->data = 10;
	n1->left = n2;
	n1->right = n3;
	n2->data = 20;
	n2->left = NULL;
	n2->right = NULL;
	n3->data = 30;
	n3->left = NULL;
	n3->right = NULL;

	printf("최소값 = %d\n", findMin(n1));
	printf("최대값 = %d\n", findMax(n1));
	free(n1);
	free(n2);
	free(n3);

	return 0;
}