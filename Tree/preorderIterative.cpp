/* https://leetcode.com/problems/binary-tree-preorder-traversal/ */
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> preorderStack;
        preorderStack.push(root);
        vector<int> ans;
        while(!preorderStack.empty()) {
            TreeNode* node = preorderStack.top();
            preorderStack.pop();
            ans.push_back(node->val);
            if(node->right) {
                preorderStack.push(node->right);
            }
            if(node->left) {
                preorderStack.push(node->left);
            }
        }
        return ans;
    }
};