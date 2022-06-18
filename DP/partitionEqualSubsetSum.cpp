/* https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 */
#include <bits/stdc++.h>

int solve(int i, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if(target == 0) return true;
    if(i == 0) return (arr[0] == target);
    if(dp[i][target] != -1) {
        return dp[i][target];
    }
    bool c1 = solve(i-1, target, arr, dp);
    bool c2 = false;
    if(arr[i] <= target) {
        c2 = solve(i-1, target-arr[i], arr, dp);
    }
    return dp[i][target] = c1 or c2;
}

bool canPartition(vector<int> &arr, int n)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if(sum & 1) return false;
    
    // MEMOIZATION:
    /*int target = sum/2;
    vector<vector<int>> dp(n, vector<int> (target+1, -1));
    return solve(n-1, target, arr, dp);*/
    
    // TABULATION (with space optimization):
    int target = sum/2;
    // base case
    /*vector<vector<bool>> tab(n, vector<bool> (target+1, false));*/
    vector<bool> prev(target+1, 0), cur(target+1, 0);
    /*for(int i = 0; i < n; i++) {
        tab[i][0] = true;
    }
    tab[0][arr[0]] = true;*/
    prev[0] = cur[0] = true;
    if(arr[0] <= target) prev[arr[0]] = true;
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= target; j++) {
            /*bool c1 = tab[i-1][j];*/
            bool c1 = prev[j];
            bool c2 = false;
            if(arr[i] <= j) {
                /*c2 = tab[i-1][j-arr[i]];*/
                c2 = prev[j-arr[i]];
            }
            /*tab[i][j] = c1 or c2;*/
            cur[j] = c1 or c2;
        }
        prev = cur;
    }
    
    /*return tab[n-1][target];*/
    return prev[target];
}
