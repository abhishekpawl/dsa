/* https://leetcode.com/problems/coin-change/ */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1));
        for(int i = 0; i <= amount; i++) {
            /* empty set of coins, inifinity required */
            dp[0][i] = INT_MAX-1;
            /* when only one coin is there we initialize with value / coin or INT_MAX */
            if(n >= 1 && i > 0) {
                dp[1][i] = i % coins[0] ? INT_MAX-1 : i / coins[0];
            }
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i-1] <= j) {
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount] < 1e8 ? dp[n][amount] : -1;
    }
};