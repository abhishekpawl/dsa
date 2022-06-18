/* https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 */
#include <bits/stdc++.h>

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;
    sum = accumulate(arr.begin(), arr.end(), 0);
    int target = sum / 2;
    
    // MEMOIZATION (with space optimization):
    /*vector<vector<bool>> tab(n, vector<bool> (target+1, 0));*/
    vector<bool> prev(target+1, 0), cur(target+1, 0);
    // base case
    /*for(int i = 0; i < n; i++) tab[i][0] = true;
    if(arr[0] <= target) tab[0][arr[0]] = true;*/
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
    bool flag = true;
    int minSum = -1;
    int i = target;
    while(flag) {
        /*if(tab[n-1][i]) {*/
        if(prev[i]) {
            flag = false;
            minSum = i;
        }
        i--;
    }
    int maxSum = sum - minSum;
    return maxSum - minSum;
}
