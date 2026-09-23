/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) {
        return head;
    }

    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    struct ListNode* current_tail = &dummy;

    struct ListNode** stack = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    int stack_size = 0;

    struct ListNode* curr = head;
    while (curr) {
        while (curr && stack_size < k) {
            stack[stack_size] = curr;
            stack_size++;
            curr = curr->next;
        }
        if (stack_size == k) {
            while (stack_size > 0) {
                stack_size--;
                struct ListNode* node = stack[stack_size];
                current_tail->next = node;
                current_tail = current_tail->next;
            }
            current_tail->next = NULL;
        } 
        else {
            if (stack_size > 0) {
                current_tail->next = stack[0];
            }
        }
    }

    free(stack);
    return dummy.next;
}
