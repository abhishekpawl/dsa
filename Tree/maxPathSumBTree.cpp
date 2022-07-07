/* https://www.codingninjas.com/codestudio/problems/binary-tree-maximum-path-sum_1280142?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0 */
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

int solve(TreeNode<int> *root, int &res) {
    if(root == NULL) return 0;
    int ls = solve(root->left, res);
    int rs = solve(root->right, res);
    int temp = max(root->val + max(ls, rs), root->val);
    int ans = max(temp, root->val+ls+rs);
    res = max(res, ans);
    return temp;
}

int maxPathSum(TreeNode<int>* root)
{
    if(root == NULL) return 0;
    int res = INT_MIN;
    int temp = solve(root, res);
    return res;
}