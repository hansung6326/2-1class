#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

typedef struct TreeNode {
	int weight;
	char ch;
	struct TreeNode* left, * right;
}TreeNode;

typedef struct {
	TreeNode* ptr;
	char ch;
	int key;
}element;

typedef struct {
	element heap[SIZE];
	int size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) {
	h->size = 0;
}

void insert(HeapType* h, element item) {
	int i;
	i = ++h->size;

	while (i != 1 && item.key < h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;

}

element delete(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[h->size--];
	parent = 1;
	child = 2;
	while (child <= h->size) {
		if (h->heap[child].key > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

TreeNode* make_tree(TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}

//이진 트리 제거 함수
void destroy_tree(TreeNode* root) {
	if (!root)
		return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

int is_leaf(TreeNode* root) {
	return !(root->left) && !(root->right); // left right 둘다 NULL이 아니라면 true
}

void print_array(int codes[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", codes[i]);
	}
	printf("\n");
}

void print_codes(TreeNode* root, int codes[], int top) {
	if (root->left) {
		codes[top] = 1;
		print_codes(root->left, codes, top + 1);
	}
	if (root->right) {
		codes[top] = 0;
		print_codes(root->right, codes, top + 1);
	}
	if (is_leaf(root)) {
		printf("%c: ", root->ch);
		print_array(codes, top);
	}
}

void huffman_tree(int freq[], char ch_list[], int n) {
	int i;
	TreeNode* node, * x;
	HeapType* heap;
	element e, e1, e2;
	int codes[100];
	int top = 0;

	heap = create();
	init(heap);

	for (int i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptr = node;
		insert(heap, e);
	}
	for (int i = 1; i < n; i++) {
		e1 = delete(heap);
		e2 = delete(heap);
		x = make_tree(e1.ptr, e2.ptr);
		e.key = x->weight = e1.key + e2.key;
		e.ptr = x;
		printf("%d+%d->%d \n", e1.key, e2.key, e.key);
		insert(heap, e);
	}

	e = delete(heap);
	print_codes(e.ptr, codes, top);
	destroy_tree(e.ptr);
	free(heap);
}

int main() {
	char ch_list[] = {'s', 'i', 'n', 't', 'e'};
	int freq[] = { 4, 6, 8, 12, 15 };
	huffman_tree(freq, ch_list, 5);
}