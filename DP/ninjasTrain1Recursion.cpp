/* https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003 */
#include <bits/stdc++.h>

int solve(int n, int last, vector<vector<int>> &points) {
    if(n == 0) {
        int maxPoint = 0;
        for(int i = 0; i < 3; i++) {
            if(i != last){
                maxPoint = max(maxPoint, points[n][i]);
            }
        }
        return maxPoint;
    }
    vector<int> choice;
    int i = 0;
    for(int j = 0; j < 3; j++) {
        if(j != last) {
            choice.push_back(points[n][j] + solve(n-1, j, points));
        }
    }
    return max(choice[0], choice[1]);
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int c0, c1, c2;
    c0 = solve(n-1, 0, points);
    c1 = solve(n-1, 1, points);
    c2 = solve(n-1, 2, points);
    return max(c0, max(c1, c2));
}