/* https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 */
#include <bits/stdc++.h>

/*
int solve(int i, vector<int> &nums, vector<int> &dp) {
    if(i == 0) {
        return nums[i];
    }
    if(i < 0) {
        return 0;
    }
    if(dp[i] != -1) {
        return dp[i];
    }
    int c1 = nums[i] + solve(i-2, nums, dp);
    int c2 = solve(i-1, nums, dp);
    return dp[i] = max(c1, c2);
}
*/

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    /*
    vector<int> dp(nums.size(), -1);
    return solve(nums.size()-1, nums, dp);
    */
    if(nums.size() == 1) {
        return nums[0];
    }
    if(nums.size() == 2) {
        return max(nums[0], nums[1]);
    }
    int prevPicked, prevNotPicked;
    prevNotPicked = nums[0];
    prevPicked = nums[1];
    int i = 2;
    while(i != nums.size()) {
        int cur = max(nums[i] + prevNotPicked, prevPicked);
        prevNotPicked = prevPicked;
        prevPicked = cur;
        i++;
    }
    return prevPicked;
}