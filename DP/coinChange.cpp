/* https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 */
#include <bits/stdc++.h>

long solve(int ind, int tar, int *denominations, vector<vector<long>> &dp) {
    if(ind == 0) {
        if(tar % denominations[0] == 0) return 1;
        return 0;
    }
    if(dp[ind][tar] != -1) {
        return dp[ind][tar];
    }
    int c1 = solve(ind-1, tar, denominations, dp);
    int c2 = 0;
    if(denominations[ind] <= tar) {
        c2 = solve(ind, tar-denominations[ind], denominations, dp);
    }
    return dp[ind][tar] = c1 + c2;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // MEMOIZATION:
    /*vector<vector<long>> dp(n, vector<long> (value+1, -1));
    return solve(n-1, value, denominations, dp);*/
    
    // TABULATION:
    //vector<vector<long>> tab(n, vector<long> (value+1, 0));
    vector<long> prev(value+1, 0);
    
    for(int i = 0; i <= value; i++) {
        if(i % denominations[0] == 0) {
            //tab[0][i] = 1;
            prev[i] = 1;
        }
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= value; j++) {
            //long c1 = tab[i-1][j];
            long c1 = prev[j];
            long c2 = 0;
            if(denominations[i] <= j) {
                //c2 = tab[i][j-denominations[i]];
                c2 = prev[j-denominations[i]];
            }
            //tab[i][j] = c1 + c2;
            prev[j] = c1 + c2;
        }
    }
    
    //return tab[n-1][value];
    return prev[value];
}