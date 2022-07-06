/* https://leetcode.com/problems/is-graph-bipartite/ */
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, -1);
        
        for(int i = 0; i < V; i++) {
            if(vis[i] == -1) {
                queue<int> bfs;
                bfs.push(i);
                vis[i] = 1;
                while(!bfs.empty()) {
                    int node = bfs.front();
                    bfs.pop();
                    for(int nei: graph[node]) {
                        if(vis[nei] == -1) {
                            vis[nei] = 1-vis[node];
                            bfs.push(nei);
                        } else if(vis[nei] == vis[node]) {
                            return false;
                        } else {
                            continue;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};