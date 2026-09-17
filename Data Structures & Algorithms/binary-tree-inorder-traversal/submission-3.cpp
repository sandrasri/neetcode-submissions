/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> solution;
        stack<TreeNode*> stac;
        TreeNode* curr = root;

        while (curr != nullptr || !stac.empty()) {
            while (curr != nullptr) {
                stac.push(curr);
                curr = curr->left;
            }
            curr = stac.top();
            stac.pop();
            solution.push_back(curr->val);
            curr = curr->right;
        }
        return solution;

    }
};