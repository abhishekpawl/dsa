/* https://leetcode.com/problems/number-of-longest-increasing-subsequence/ */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        //count[n-1] = 1;
        int maxi = 1;
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] < nums[j]) {
                    if(dp[i] == 1 + dp[j]) {
                        count[i] += count[j];
                    } else if(dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    }
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
            }
        }
        
        int ans{};
        for(int i = 0; i < n; i++) {
            //cout<<dp[i]<<","<<count[i]<<"--";
            if(dp[i] == maxi) {
                ans += count[i];
            }
        }
        
        return ans;
    }
};

/*

          1 2 4 3 5 4 7 2

dp =      5 4 3 3 2 2 1 1
count =   3 3 1 2 1 1 1 1

 */