#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
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
	i = ++(h->size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
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
		if (child < h->size && h->heap[child].key < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(element a[], int n) {
	int i;
	HeapType* h;
	h = create();
	init(h);

	for (int i = 0; i < n; i++) {
		insert(h, a[i]);
	}
	for (int i = (n - 1); i >= 0; i--) {
		a[i] = delete(h);
	}
	free(h);
}

int main() {
	element list[8] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	heap_sort(list, 8);
	for (int i = 0; i < 8; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");
}


