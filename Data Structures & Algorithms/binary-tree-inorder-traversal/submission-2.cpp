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

        auto inorder = [&](auto& self, TreeNode* node) -> void {
            if (node == nullptr) {
                return;
            }
            
            self(self, node->left);
            solution.push_back(node->val);
            self(self, node->right);
        };

        inorder(inorder, root);
        return solution;

    }
};