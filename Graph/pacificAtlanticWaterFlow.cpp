/* https://leetcode.com/problems/pacific-atlantic-water-flow/ */
class Solution {
public:
    void dfs(int i, int j, int prev, vector<vector<bool>> &vis, vector<vector<int>> &heights) {
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) return;
        if(vis[i][j] == true || heights[i][j] < prev) return;
        
        int x = heights[i][j];
        vis[i][j] = true;
        dfs(i+1, j, x, vis, heights);
        dfs(i-1, j, x, vis, heights);
        dfs(i, j+1, x, vis, heights);
        dfs(i, j-1, x, vis, heights);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<bool>> pac(row, vector<bool> (col, false));
        vector<vector<bool>> atl(row, vector<bool> (col, false));
        
        for(int i = 0; i < row; i++) {
            dfs(i, 0, heights[i][0], pac, heights);
            dfs(i, col-1, heights[i][col-1], atl, heights);
        }
        
        for(int j = 0; j < col; j++) {
            dfs(0, j, heights[0][j], pac, heights);
            dfs(row-1, j, heights[row-1][j], atl, heights);
        }
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};