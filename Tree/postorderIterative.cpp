/* https://leetcode.com/problems/binary-tree-postorder-traversal/ */
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        
        stack<TreeNode*> s1;
        vector<int> ans;
        s1.push(root);
        while(!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            ans.push_back(node->val);
            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};