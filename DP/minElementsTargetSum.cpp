/* https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0 */
#include <bits/stdc++.h>

int solve(int ind, int tar, vector<int> &num, vector<vector<int>> &dp) {
    if(ind == 0) {
        if(tar % num[0] == 0) return (int)(tar / num[0]);
        else return 1e8;
    }
    if(dp[ind][tar] != -1) return dp[ind][tar];
    int c1 = solve(ind-1, tar, num, dp);
    int c2 = 1e8;
    if(num[ind] <= tar) {
        c2 = 1 + solve(ind, tar - num[ind], num, dp);
    }
    return dp[ind][tar] = min(c1, c2);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    // MEMOIZATION:
    /*vector<vector<int>> dp(num.size(), vector<int> (x+1, -1));
    int ans = solve(num.size()-1, x, num, dp);
    return (ans >= 1e8) ? -1 : ans;*/
    
    // TABULATION (with space optimization):
    /*vector<vector<int>> tab(n, vector<int> (x+1, 0));*/
    vector<int> prev(x+1, 0);
    for(int i = 0; i <= x; i++) {
        /*if(i % num[0] == 0) tab[0][i] = i / num[0];*/
        if(i % num[0] == 0) prev[i] = i / num[0];
        else prev[i] = 1e8;
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= x; j++) {
            /*int c1 = tab[i-1][j];*/
            int c1 = prev[j];
            int c2 = 1e8;
            if(num[i] <= j) {
                /*c2 = 1 + tab[i][j-num[i]];*/
                c2 = 1 + prev[j-num[i]];
            }
            /*tab[i][j] = min(c1, c2);*/
            prev[j] = min(c1, c2);
        }
    }
    
    /*if(tab[n-1][x] >= 1e8) return -1;*/
    if(prev[x] >= 1e8) return -1;
    /*else return tab[n-1][x];*/
    else return prev[x];
}