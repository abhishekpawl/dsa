/* https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0 */
#include <bits/stdc++.h>

bool solve(int ind, int target, vector<int> &a, vector<vector<int>> &dp) {
    if(target == 0) {
        return true;
    }
    if(ind == 0) {
        return (a[0] == target);
    }
    if(dp[ind][target] != -1) {
        return dp[ind][target];
    }
    bool c1 = solve(ind-1, target, a, dp);
    bool c2 = false;
    if(a[ind] <= target) {
        c2 = solve(ind-1, target-a[ind], a, dp);
    }
    return dp[ind][target] = (c1 | c2) ? 1 : 0;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // MEMOIZATION:
    //vector<vector<int>> dp(n, vector<int> (k+1, -1));
    //return solve(n-1, k, arr, dp);
    
    // TABULATION:
    vector<vector<bool>> tab(n, vector<bool> (k+1, false));
    // base case
    for(int i = 0; i < n; i++) {
        tab[i][0] = true;
    }
    tab[0][arr[0]] = true;
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            bool c1 = tab[i-1][j];
            bool c2 = false;
            if(arr[i] <= j) {
                c2 = tab[i-1][j-arr[i]];
            }
            tab[i][j] = c1 or c2;
        }
    }
    
    return tab[n-1][k];
}