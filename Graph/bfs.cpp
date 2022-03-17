/* https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/# */
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        vector<int> bfs;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);

                    for(auto it: adj[node]) {
                        if(!vis[it]) {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }

        return bfs;
    }
};

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        vector<int> bfs;
        
        for(int i = 0; i < V; i++) {
            if(i == 0) {
                if(!vis[i]) {
                    queue<int> q;
                    q.push(i);
                    vis[i] = 1;
                    
                    while(!q.empty()) {
                        int node = q.front();
                        q.pop();
                        bfs.push_back(node);
                        
                        for(auto it: adj[node]) {
                            if(!vis[it]) {
                                q.push(it);
                                vis[it] = 1;
                            }
                        }
                    }
                }
            }
        }
        
        return bfs;
    }
};