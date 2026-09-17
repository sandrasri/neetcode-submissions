/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int*solution = (int*)malloc(100*sizeof(int));
    int index = 0;

    struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int top = -1;

    struct TreeNode* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            top++;
            stack[top] = curr;
            curr = curr->left;
        }
        curr = stack[top];
        top--;

        solution[index] = curr->val;
        index++;

        curr = curr->right;
    }
    *returnSize = index;
    return solution;
}
