/* https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 */
#include <bits/stdc++.h>

// Memoization
int solve(int m, int n, vector<vector<int>> &dp) {
    if(dp[m][n] != -1) {
        return dp[m][n];
    }
    if(m == 0 && n == 0) {
        return dp[m][n] = 1;
    }
    if(m == 0) {
        return dp[m][n] = solve(m, n-1, dp);
    }
    if(n == 0) {
        return dp[m][n] = solve(m-1, n, dp);
    }
    return dp[m][n] = solve(m-1, n, dp) + solve(m, n-1, dp);
}

int uniquePaths(int m, int n) {
    //vector<vector<int>> dp(m, vector<int> (n, -1));
    //return solve(m-1, n-1, dp);
    
    // TABULATION:
    /*vector<vector<int>> tab(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || j == 0) {
                tab[i][j] = 1;
            }
        }
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            tab[i][j] = tab[i-1][j] + tab[i][j-1];
        }
    }
    return tab[m-1][n-1];*/
    
    // SPACE OPTIMIZATION:
    vector<int> dp(n, 0);
    int i = 1;
    while(i <= m) {
        dp[0] = 1;
        for(int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j-1];
        }
        i++;
    }
    return dp[n-1];
}