/* https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 */
#include <bits/stdc++.h>

int solve(int m, int n, string s, string t, vector<vector<int>> &dp) {
    if(m == 0) {
        return 0;
    }
    if(n == 0) {
        return 0;
    }
    if(dp[m][n] != -1) return dp[m][n];
    if(s[m-1] == t[n-1]) {
        return 1 + solve(m-1, n-1, s, t, dp);
    }
    return dp[m][n] = max(solve(m-1, n, s, t, dp), solve(m, n-1, s, t, dp));
}

int lcs(string s, string t)
{
    int m = s.length();
    int n = t.length();
    
    // MEMOIZATION:
    /*vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    return solve(m, n, s, t, dp);*/
    
    // TABULATION:
    //vector<vector<int>> tab(m+1, vector<int> (n+1, 0));
    vector<int> prev(n+1, 0), cur(n+1, 0);
    
    //for(int i = 0; i <= m; i++) tab[i][0] = 0;
    //for(int j = 0; j <= n; j++) tab[0][j] = 0;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == t[j-1]) {
                cur[j] = 1 + prev[j-1];
            } else {
                cur[j] = max(prev[j], cur[j-1]);
            }
        }
        prev = cur;
    }
    
    return prev[n];
}