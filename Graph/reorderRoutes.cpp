/* https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/ */
class Solution {
    int c = 0;
public:
    
    void dfs(int node, vector<int> *neighbors, set<int> *path, vector<bool> &visit) {
        for(int x: neighbors[node]) {
            if(visit[x]) continue;
            if(path[node].find(x) == path[node].end()) {
                c++;
            }
            visit[x] = true;
            dfs(x, neighbors, path, visit);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> neighbors[n];
        set<int> path[n];
        vector<bool> visit(n, false);
        
        for(auto v: connections) {
            neighbors[v[0]].push_back(v[1]);
            neighbors[v[1]].push_back(v[0]);
            path[v[1]].insert(v[0]);
        }
        
        visit[0] = true;
        dfs(0, neighbors, path, visit);
        
        return c;
    }
};