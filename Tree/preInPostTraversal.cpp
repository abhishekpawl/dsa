/*
  preorder, inorder, postorder traversal in one stack
  stack ---> (element, num)           num -> 1, 2, 3
  (el, 1)
    1. push to preorder
    2. re-insert (el, 2)
    3. if left -> s.push(left)
  (el, 2)
    1. push to inorder
    2. re-insert (el, 3)
    3. if left -> s.push(right)
  (el, 3)
    1. push to postorder
*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct TreeNode {
  T val;
  TreeNode<T> *left;
  TreeNode<T> *right;

  TreeNode(T val) : val(val), left(nullptr), right(nullptr) { }
};

vector<vector<int>> traversals(TreeNode<int> *root) {
  if(root == NULL) return {{}};

  vector<int> pre, in, post;
  stack<pair<TreeNode<int>*, int>> s;
  s.push({root, 1});

  while(!s.empty()) {
    auto node = s.top();
    s.pop();
    if(node.second == 1) {
      auto x = node.first;
      pre.push_back(x->val);
      s.push({x, 2});
      if(x->left) s.push({x->left, 1});
    } else if(node.second == 2) {
      auto x = node.first;
      in.push_back(x->val);
      s.push({x, 3});
      if(x->right) s.push({x->right, 1});
    } else {
      auto x = node.first;
      post.push_back(x->val);
    }
  }

  vector<vector<int>> ans;
  ans.push_back(pre);
  ans.push_back(in);
  ans.push_back(post);

  return ans;
}

int main() {
  TreeNode<int> *root = new TreeNode<int>(1);
  root->left = new TreeNode<int>(2);
  root->right = new TreeNode<int>(5);
  root->left->left = new TreeNode<int>(3);
  root->left->right = new TreeNode<int>(4);
  root->right->left = new TreeNode<int>(6);
  root->right->right = new TreeNode<int>(7);

  vector<vector<int>> ans = traversals(root);

  for(auto vs: ans) {
    for(int x: vs) {
      cout<<x<<" ";
    }
    cout<<endl;
  }

  return 1;
}