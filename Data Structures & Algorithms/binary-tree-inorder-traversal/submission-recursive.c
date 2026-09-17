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

void traverse(struct TreeNode* node, int* arr, int*index) {
    if (node == NULL) {
        return;
    }

    traverse(node->left, arr, index);
    arr[*index] = node->val;
    (*index)++;
    traverse(node->right, arr, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int*solution = (int*)malloc(100*sizeof(int));

    int index = 0;
    traverse(root, solution, &index);

    *returnSize = index;
    return solution;
}
