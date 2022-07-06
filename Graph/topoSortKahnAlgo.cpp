class Solution
{
	public:
	void dfs(int node, vector<bool> &vis, stack<int> &s, vector<int> *adj) {
	    vis[node] = true;
	    for(int nei: adj[node]) {
	        if(!vis[nei]) {
	            dfs(nei, vis, s, adj);
	        }
	    }
	    s.push(node);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> vis(V, false);
	    stack<int> s;
	    
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) {
	            dfs(i, vis, s, adj);
	        }
	    }
	    
	    vector<int> ans;
	    while(!s.empty()) {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
};