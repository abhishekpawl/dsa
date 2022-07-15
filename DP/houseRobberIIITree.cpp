/* https://leetcode.com/problems/house-robber-iii/ */
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
   /*int solve(TreeNode* root, int last) {
        if(root == NULL) return 0;
        if(last == 1) return solve(root->left, 0) + solve(root->right, 0);
        int c1, c2;
        c1 = solve(root->left, 0) + solve(root->right, 0);
        c2 = root->val + solve(root->left, 1) + solve(root->right, 1);
        return max(c1, c2);
    }*/
    vector<int> solve(TreeNode* root) {
        if(root == NULL) return {0, 0};
        
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        
        vector<int> cur(2);
        
        cur[0] = max(left[0], left[1]) + max(right[0], right[1]);
        cur[1] = root->val + left[0] + right[0];
        
        return cur;
    }
    
    int rob(TreeNode* root) {
        auto ans = solve(root);
        return max(ans[0], ans[1]);
    }
};