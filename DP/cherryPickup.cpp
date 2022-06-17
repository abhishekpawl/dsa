/* https://leetcode.com/problems/cherry-pickup-ii/ */
class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if(j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size()) {
            return -1e8;
        }
        if(i == grid.size() - 1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        int maxi = 0;
        // movement of j for robot #1
        for(int d1 = -1; d1 <= 1; d1++) {
            // movement of j for robot #2
            for(int d2 = -1; d2 <= 1; d2++) {
                if(j1 == j2) maxi = max(maxi, grid[i][j1] + solve(i+1, j1+d1, j2+d2, grid, dp));
                else maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i+1, j1+d1, j2+d2, grid, dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>> (col, vector<int> (col, -1)));
        return solve(0, 0, grid[0].size()-1, grid, dp);
    }
};