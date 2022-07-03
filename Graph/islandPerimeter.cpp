/* https://leetcode.com/problems/island-perimeter/ */
class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>> &grid) {
        if(i < 0 || j < 0 || i >= m || j >= n) return 1;
        if(grid[i][j] == 0) return 1;
        if(grid[i][j] == -1) return 0;
        
        grid[i][j] = -1;
        return dfs(i+1, j, m, n, grid) +
            dfs(i, j+1, m, n, grid) +
            dfs(i-1, j, m, n, grid) +
            dfs(i, j-1, m, n, grid);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    return dfs(i, j, m, n, grid);
                }
            }
        }
        
        return 2*(m+n);
    }
};