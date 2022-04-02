/* https://leetcode.com/problems/valid-palindrome-ii/ */
class Solution {
public:
    bool solve(string &s, int i, int j, int flag) {
        if(i >= j) {
            return true;
        }
        if(s[i] == s[j]) {
            return solve(s, i+1, j-1, flag);
        }
        if(flag == 1) {
            return false;
        }
        return solve(s, i+1, j, !flag) || solve(s, i, j-1, !flag);
    }
    
    bool validPalindrome(string s) {
        return solve(s, 0, s.length()-1, 0);
    }
};