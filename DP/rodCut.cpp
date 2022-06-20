/* https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 */
#include <bits/stdc++.h>

int solve(int ind, int len, vector<int> &price, vector<vector<int>> &dp) {
    if(len == 0) return 0;
    if(ind == 1) {
        return len * price[0];
    }
    if(dp[ind][len] != -1) {
        return dp[ind][len];
    }
    int c1 = solve(ind-1, len, price, dp);
    int c2 = 0;
    if(ind <= len) {
        c2 = price[ind-1] + solve(ind, len-ind, price, dp);
    }
    return dp[ind][len] = max(c1, c2);
}

int cutRod(vector<int> &price, int n)
{
    // MEMOIZATION:
    /*vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    return solve(n, n, price, dp);*/
    
    // TABULATION (with space optimization):
    //vector<vector<int>> tab(n+1, vector<int> (n+1, 0));
    vector<int> prev(n+1, 0);
    
    for(int i = 1; i <= n; i++) {
        //tab[1][i] = i * price[0];
        prev[i] = i * price[0];
    }
    
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            //int c1 = tab[i-1][j];
            int c1 = prev[j];
            int c2 = 0;
            if(i <= j) {
                //c2 = price[i-1] + tab[i][j-i];
                c2 = price[i-1] + prev[j-i];
            }
            //tab[i][j] = max(c1, c2);
            prev[j] = max(c1, c2);
        }
    }
    
    //return tab[n][n];
    return prev[n];
}
