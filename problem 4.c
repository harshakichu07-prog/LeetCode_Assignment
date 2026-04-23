25. Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prevGroupEnd = &dummy;

    while (1) {
        struct ListNode* kth = prevGroupEnd;
        for (int i = 0; i < k && kth; i++) {
            kth = kth->next;
        }
        if (!kth) break;

        struct ListNode* groupStart = prevGroupEnd->next;
        struct ListNode* nextGroupStart = kth->next;

        // Standard reversal logic but restricted to the k-group
        struct ListNode* prev = nextGroupStart;
        struct ListNode* curr = groupStart;
        while (curr != nextGroupStart) {
            struct ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // Connect the reversed group back to the main list
        prevGroupEnd->next = kth;
        prevGroupEnd = groupStart;
    }

    return dummy.next;
}
