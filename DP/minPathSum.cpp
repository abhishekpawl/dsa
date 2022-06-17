/* https://leetcode.com/problems/minimum-path-sum/ */
class Solution {
public:
    /*int solve(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(n == 0 && m == 0) {
            return grid[m][n];
        }
        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        if(m == 0) {
            return dp[m][n] = grid[m][n] + solve(m, n-1, grid, dp);
        }
        if(n == 0) {
            return grid[m][n] + solve(m-1, n, grid, dp);
        }
        return dp[m][n] = grid[m][n] + min(solve(m-1, n, grid, dp), solve(m, n-1, grid, dp));
    }*/
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //vector<vector<int>> dp(m, vector<int> (n, -1));
        //return solve(m-1, n-1, grid, dp);
        
        // TABULATION:
        vector<vector<int>> tab(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    tab[0][0] = grid[0][0];
                } else if(i == 0) {
                    tab[i][j] = grid[i][j] + tab[i][j-1];
                } else if(j == 0) {
                    tab[i][j] = grid[i][j] + tab[i-1][j];
                } else {
                    tab[i][j] = grid[i][j] + min(tab[i][j-1], tab[i-1][j]);
                }
            }
        
        return tab[m-1][n-1];
    }
};