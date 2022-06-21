/* https://leetcode.com/problems/decode-ways/ */
#include <bits/stdc++.h>

class Solution {
public:
    int solve(int i, string &s, vector<int> &dp) {
        if(i == 0) return 1;
        if(i == 1) {
            if(s[i-1] == '0') return 0;
            return 1;
        }
        
        if(dp[i] != -1) return dp[i];
        
        int c1=0, c2=0;
        
        int num = (int)(s[i-2]-'0') * 10 + (int)(s[i-1]-'0');
        
        if((s[i-2] == '0' && s[i-1] == 0) || s[i-2] == '0' || num > 26) c2 = 0;
        else c2 = solve(i-2, s, dp);
        
        if(s[i-1] == '0') c1 = 0;
        else c1 = solve(i-1, s, dp);
        
        return dp[i] = c1 + c2;
    }
    
    int numDecodings(string s) {
        // MEMOIZATION:
        //vector<int> dp(s.length()+1, -1);
        //return solve(s.length(), s, dp);
        
        // TABULATION (with space optimization):
        //vector<int> tab(s.length()+1, 0);
        //tab[0] = 1;
        //if(s[0] == '0') tab[1] = 0;
        //else tab[1] = 1;
        
        if(s.length() == 1) {
            if(s[0] == '0') return 0;
            else return 1;
        }
        
        int p1, p2;
        p2 = 1;
        if(s[0] == '0') p1 = 0;
        else p1 = 1;
        
        for(int i = 2; i <= s.length(); i++) {
            int c1=0, c2=0;
            int num = (int)(s[i-2]-'0') * 10 + (int)(s[i-1]-'0');
            
            if((s[i-2] == '0' && s[i-1] == 0) || s[i-2] == '0' || num > 26) c2 = 0;
            else c2 = p2;

            if(s[i-1] == '0') c1 = 0;
            else c1 = p1;
            
            p2 = p1;
            p1 = c1 + c2;
        }
        
        return p1;
    }
};