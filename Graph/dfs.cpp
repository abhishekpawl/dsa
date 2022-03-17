// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void dfs_recursion(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfs) {
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs.push_back(it);
                vis[it] = 1;
                dfs_recursion(it, vis, adj, dfs);
            }
        }
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V+1, 0);
        vector<int> dfs;
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs.push_back(i);
                vis[i] = 1;
                dfs_recursion(i, vis, adj, dfs);
            }
            
        }
        
        return dfs;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends