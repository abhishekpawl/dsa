/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/ */
#define vi vector<int>
#define vvi vector<vector<int>>

class Solution {
public:
    int solve(int i, int buy, vi &prices, int n, vvi &dp) {
        if(i == n) {
            return 0;
        }
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit;
        if(buy) {
            profit = max(-prices[i]+solve(i, !buy, prices, n, dp), solve(i+1, buy, prices, n, dp));
        } else {
            profit = max(prices[i]+solve(i+1, !buy, prices, n, dp), solve(i+1, buy, prices, n, dp));
        }
        return dp[i][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vvi dp(n+1, vi (2, -1));
        //return solve(0, 1, prices, n, dp);
        
        // TABULATION:
        //vvi dp(n+1, vi (2, 0));
        vi ahead(2, 0), cur(2, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < 2; j++) {
                int profit;
                if(j) {
                    profit = max(-prices[i]+cur[!j], ahead[j]);
                } else {
                    profit = max(prices[i]+ahead[!j], ahead[j]);
                }
                cur[j] = profit;
            }
            ahead = cur;
        }
        
        return ahead[1];
    }
};