/* https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 */
#include <bits/stdc++.h>

// MEMOIZATION:
int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    if(i == triangle.size() - 1) {
        return dp[i][j] = triangle[i][j];
    }
    return dp[i][j] = triangle[i][j] + min(solve(i+1, j, triangle, dp), solve(i+1, j+1, triangle, dp));
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
    // vector<vector<int>> dp(n, vector<int> (n, -1));
	// return solve(0, 0, triangle, dp);
    
    // TABULATION:
    /*vector<vector<int>> tab(n, vector<int> (n, 0));
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            if(i == n-1) {
                tab[i][j] = triangle[i][j];
            } else {
                tab[i][j] = triangle[i][j] + min(tab[i+1][j], tab[i+1][j+1]);
            }
        }
    }
    return tab[0][0];*/
    
    // SPACE OPTIMIZATION ON TABULATION:
    vector<int> tabso(n);
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            if(i == n-1) {
                tabso[j] = triangle[i][j];
            } else {
                tabso[j] = triangle[i][j] + min(tabso[j], tabso[j+1]);
            }
        }
    }
    return tabso[0];
}