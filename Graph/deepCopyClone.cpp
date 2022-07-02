/* https://leetcode.com/problems/clone-graph/ */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs_deep_clone(Node* node, map<Node*, Node*> &hash) {
        if(hash.find(node) != hash.end()) return hash[node];
        
        Node* copy = new Node(node->val);
        hash[node] = copy;
        for(auto it: node->neighbors) {
            copy->neighbors.push_back(dfs_deep_clone(it, hash));
        }
        
        return copy;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        map<Node*, Node*> hash;
        
        return dfs_deep_clone(node, hash);
    }
};