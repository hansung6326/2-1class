#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int get_node_cout(TreeNode* root) {
	int count = 0;
	if (root) {
		count = 1 + get_node_cout(root->left) + get_node_cout(root->right);
	}
	return count;
}

int get_height(TreeNode* root) {
	int height = 0;
	if (root) {
		height = 1 + max(get_height(root->left), get_height(root->right));
	}
	return height;
}

int get_leaf_count(TreeNode* root) {
	int count = 0;
	if (root) {
		if (root->left == NULL && root->right == NULL)
			return 1;
		else
			count = get_leaf_count(root->left) + get_leaf_count(root->right);
	}
	return count;
}