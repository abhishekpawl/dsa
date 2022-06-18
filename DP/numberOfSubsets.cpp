/* https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 */
#include <bits/stdc++.h>

int solve(int i, int tar, vector<int> &num, vector<vector<int>> &dp) {
    if(tar == 0) return 1;
    if(i == 0) return (num[i] == tar);
    if(dp[i][tar] != -1) {
        return dp[i][tar];
    }
    int c1 = solve(i-1, tar, num, dp);
    int c2 = false;
    if(num[i] <= tar) {
        c2 = solve(i-1, tar-num[i], num, dp);
    }
    return dp[i][tar] = c1 + c2;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    
    // MEMOIZATION
    /*vector<vector<int>> dp(n, vector<int> (tar+1, -1));
    return solve(num.size()-1, tar, num, dp);*/
    
    // TABULATION (with space optimization):
    /*vector<vector<int>> tab(n, vector<int> (tar+1, 0));
    for(int i = 0; i < n; i++) tab[i][0] = true;
    if(num[0] <= tar) tab[0][num[0]] = true;*/
    vector<int> prev(tar+1, 0), cur(tar+1, 0);
    prev[0] = cur[0] = true;
    if(num[0] <= tar) prev[num[0]] = true;
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= tar; j++) {
            /*int c1 = tab[i-1][j];*/
            int c1 = prev[j];
            int c2 = 0;
            if(num[i] <= j) {
                /*c2 = tab[i-1][j-num[i]];*/
                c2 = prev[j-num[i]];
            }
            /*tab[i][j] = c1 + c2;*/
            cur[j] = c1 + c2;
        }
        prev = cur;
    }
    
    /*return tab[n-1][tar];*/
    return prev[tar];
}