/* https://www.codingninjas.com/codestudio/problems/spiral-order-traversal-of-a-binary-tree_630521?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0 */
/************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
************************************************************/

vector<int> spiralOrder(BinaryTreeNode<int> *root)
{
    if(root == NULL) return {};
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    vector<int> ans;
    int dir = 0;
    while(!q.empty()) {
        int size = q.size();
        deque<int> temp;
        while(size--) {
            auto node = q.front();
            temp.push_back(node->data);
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        while(!temp.empty()) {
            if(dir == 1) {
                ans.push_back(temp.back());
                temp.pop_back();
            } else {
                ans.push_back(temp.front());
                temp.pop_front();
            }
        }
        dir = 1 - dir;
    }
    
    return ans;
}
