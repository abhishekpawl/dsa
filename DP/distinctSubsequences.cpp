/* https://leetcode.com/problems/distinct-subsequences/ */
class Solution {
public:
    int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) {
            return dp[i][j] = solve(i-1, j, a, b, dp) + solve(i-1, j-1, a, b, dp);
        }
        return dp[i][j] = solve(i-1, j, a, b, dp);
    }
    
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        //vector<vector<int>> dp(m, vector<int> (n, -1));
        //return solve(m-1, n-1, s, t, dp);
        
        // TABULATION:
        vector<vector<double>> tab(m+1, vector<double> (n+1, 0));
        for(int i = 0; i < m; i++) tab[i][0] = 1;
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == t[j-1]) {
                    tab[i][j] = tab[i-1][j] + tab[i-1][j-1];
                } else {
                    tab[i][j] = tab[i-1][j];
                }
            }
        }
        
        return (int)tab[m][n];
    }
};