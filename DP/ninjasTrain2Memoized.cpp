/* https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003 */
#include <bits/stdc++.h>

int solve(int n, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if(dp[n][last] != -1) {
        return dp[n][last];
    }
    if(n == 0) {
        int maxPoint = 0;
        for(int i = 0; i < 3; i++) {
            if(i != last){
                maxPoint = max(maxPoint, points[n][i]);
            }
        }
        return dp[n][last] = maxPoint;
    }
    vector<int> choice;
    int i = 0;
    for(int j = 0; j < 3; j++) {
        if(j != last) {
            choice.push_back(points[n][j] + solve(n-1, j, points, dp));
        }
    }
    return dp[n][last] = max(choice[0], choice[1]);
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (4, -1));
    int c0, c1, c2;
    c0 = solve(n-1, 0, points, dp);
    c1 = solve(n-1, 1, points, dp);
    c2 = solve(n-1, 2, points, dp);
    return max(c0, max(c1, c2));
}