/* https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 */
#include<bits/stdc++.h>

int solve(int ind, int wt, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp) {
    if(ind == 0) {
        if(weight[ind] <= wt) return value[ind];
        else return 0;
    }
    if(wt == 0) {
        return 0;
    }
    if(dp[ind][wt] != -1) {
        return dp[ind][wt];
    }
    int c1 = solve(ind-1, wt, weight, value, dp);
    int c2 = 0;
    if(weight[ind] <= wt) {
        c2 = value[ind] + solve(ind-1, wt-weight[ind], weight, value, dp);
    }
    return dp[ind][wt] = max(c1, c2);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // MEMOIZATION:
    /*vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
    return solve(n-1, maxWeight, weight, value, dp);*/
    
    // TABULATION (with space optimization):
    /*vector<vector<int>> tab(n, vector<int> (maxWeight+1, 0));*/
    vector<int> prev(maxWeight+1, 0), cur(maxWeight+1, 0);
    /*for(int i = weight[0]; i <= maxWeight; i++) tab[0][i] = value[0];*/
    for(int i = weight[0]; i <= maxWeight; i++) prev[i] = value[0];
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= maxWeight; j++) {
            /*int c1 = tab[i-1][j];*/
            int c1 = prev[j];
            int c2 = 0;
            if(weight[i] <= j) {
                /*c2 = value[i] + tab[i-1][j-weight[i]];*/
                c2 = value[i] + prev[j-weight[i]];
            }
            /*tab[i][j] = max(c1, c2);*/
            cur[j] = max(c1, c2);
        }
        prev = cur;
    }
    
    /*return tab[n-1][maxWeight];*/
    return prev[maxWeight];
}