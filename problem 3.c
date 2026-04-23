23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Simple Min-Heap structure for ListNode pointers
struct MinHeap {
    struct ListNode** data;
    int size;
};

void swap(struct ListNode** a, struct ListNode** b) {
    struct ListNode* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap* hp, int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < hp->size && hp->data[l]->val < hp->data[smallest]->val) smallest = l;
    if (r < hp->size && hp->data[r]->val < hp->data[smallest]->val) smallest = r;
    if (smallest != i) {
        swap(&hp->data[i], &hp->data[smallest]);
        heapify(hp, smallest);
    }
}

void push(struct MinHeap* hp, struct ListNode* node) {
    hp->data[hp->size] = node;
    int i = hp->size++;
    while (i != 0 && hp->data[(i - 1) / 2]->val > hp->data[i]->val) {
        swap(&hp->data[i], &hp->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct ListNode* pop(struct MinHeap* hp) {
    struct ListNode* root = hp->data[0];
    hp->data[0] = hp->data[--hp->size];
    heapify(hp, 0);
    return root;
}

struct ListNode* mergeKLists(struct ListNode** lists, int k) {
    struct MinHeap* hp = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    hp->data = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    hp->size = 0;

    for (int i = 0; i < k; i++) {
        if (lists[i]) push(hp, lists[i]);
    }

    struct ListNode dummy;
    struct ListNode* tail = &dummy;

    while (hp->size > 0) {
        struct ListNode* node = pop(hp);
        tail->next = node;
        tail = tail->next;
        if (node->next) push(hp, node->next);
    }

    tail->next = NULL;
    return dummy.next;
}
