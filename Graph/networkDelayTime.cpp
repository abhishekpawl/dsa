/* https://leetcode.com/problems/network-delay-time/ */
#define pii pair<int, int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // DIJKSTRA
        
        priority_queue<pii, vector<pii>, greater<pii>> minheap;
        vector<pii> adj[n+1];
        for(int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        vector<bool> vis(n+1, false);
        
        minheap.push({0, k});
        int ans = 0;
        
        while(!minheap.empty()) {
            
            auto x = minheap.top();
            minheap.pop();
            if(!vis[x.second]) {
                vis[x.second] = true;
                ans = max(ans, x.first);
                
                for(auto nei: adj[x.second]) {
                    if(!vis[nei.first]) {
                        minheap.push({nei.second + x.first, nei.first});
                    }
                }
            }
            
        }
        
        for(int i = 1; i <= n; i++)
            if(!vis[i]) return -1;
        
        return ans;
    }
};