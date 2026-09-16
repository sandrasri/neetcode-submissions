#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (!head) {
        return NULL;
    }

    struct ListNode* current_node = head;
    if (head->next) {
        current_node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
    }
    return current_node;
}
