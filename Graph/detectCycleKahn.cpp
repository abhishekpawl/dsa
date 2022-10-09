/* https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/ */
class Solution
{
	public:
	bool isCyclic(int V, vector<int> adj[]) {
		vector<int> indeg(V, 0);
		queue<int> q;
		vector<int> topo;

		for(int i = 0; i < V; i++) {
			for(int nei: adj[i]) indeg[nei]++;
		}

		for(int i = 0; i < V; i++) {
			if(indeg[i] == 0) q.push(i);
		}

		if(q.empty()) return true;

		while(!q.empty()) {
			int node = q.front();
			topo.push_back(node);
			q.pop();
			for(int nei: adj[node]) {
				indeg[nei]--;
				if(indeg[nei] == 0) {
					q.push(nei);
				}
			}
			if(q.empty() && topo.size() != V) {
				return true;
			}
		}

		return false;
	}
};