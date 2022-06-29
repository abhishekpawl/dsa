/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/ */
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>

class Solution {
public:
    int solve(int i, int buy, int c, vi &prices, int n, vvvi &dp) {
        if(i == n) {
            return 0;
        }
        if(dp[i][buy][c] != -1) return dp[i][buy][c];
        int profit;
        if(buy) {
            if(c == 2) {
                profit =  0;
            } else {
                profit = max(-prices[i]+solve(i+1, !buy, c+1, prices, n, dp), solve(i+1, buy, c, prices, n, dp));
            }
        } else {
            profit = max(prices[i]+solve(i+1, !buy, c, prices, n, dp), solve(i+1, buy, c, prices, n, dp));
        }
        return dp[i][buy][c] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vvvi dp(n+1, vvi (2, vi (3, -1)));
        //return solve(0, 1, 0, prices, n, dp);
        
        // TABULATION:
        //vvvi dp(n+1, vvi (2, vi (3, 0)));
        vvi ahead(2, vi (3, 0)), cur(2, vi (3, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 3; k++) {
                    if(j) {
                        if(k != 2) {
                            cur[j][k] = max(-prices[i]+ahead[!j][k+1], ahead[j][k]);
                        }
                    } else {
                        cur[j][k] = max(prices[i]+ahead[!j][k], ahead[j][k]);
                    }
                }
            }
            ahead = cur;
        }
        
        return ahead[1][0];
    }
};