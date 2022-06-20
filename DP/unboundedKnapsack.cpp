/* https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 */
#include <bits/stdc++.h>

int solve(int ind, int wt, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
    if(ind == 0) {
        return (int)(wt / weight[0]) * profit[0];
    }
    if(wt == 0) return 0;
    if(dp[ind][wt] != -1) return dp[ind][wt];
    int c1 = solve(ind-1, wt, profit, weight, dp);
    int c2 = 0;
    if(weight[ind] <= wt) {
        c2 = profit[ind] + solve(ind, wt-weight[ind], profit, weight, dp);
    }
    return dp[ind][wt] = max(c1, c2);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // MEMOIZATION
    /*vector<vector<int>> dp(n, vector<int> (w+1, -1));
    return solve(n-1, w, profit, weight, dp);*/
    
    // TABULATION (with space optimization):
    //vector<vector<int>> tab(n, vector<int> (w+1, 0));
    vector<int> prev(w+1, 0);
    
    for(int i = 0; i <= w; i++) {
        //tab[0][i] = (int)(i / weight[0]) * profit[0];
        prev[i] = (int)(i / weight[0]) * profit[0];
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= w; j++) {
            //int c1 = tab[i-1][j];
            int c1 = prev[j];
            int c2 = 0;
            if(weight[i] <= j) {
                //c2 = profit[i] + tab[i][j-weight[i]];
                c2 = profit[i] + prev[j-weight[i]];
            }
            //tab[i][j] = max(c1, c2);
            prev[j] = max(c1, c2);
        }
    }
    
    //return tab[n-1][w];
    return prev[w];
}
