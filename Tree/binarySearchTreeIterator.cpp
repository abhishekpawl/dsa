/* https://leetcode.com/problems/binary-search-tree-iterator/ */
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
class BSTIterator {
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* temp = root;
        while(temp) {
            s.push(temp);
            temp = temp->left;
        }
    }
    
    int next() {
        TreeNode* x = s.top();
        s.pop();
        TreeNode* temp = x->right;
        while(temp) {
            s.push(temp);
            temp = temp->left;
        }
        return x->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */