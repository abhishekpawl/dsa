/* https://leetcode.com/problems/combination-sum-iii/ */
class Solution {
public:
    void solve(int k, int n, int cur, vector<int> sub, vector<vector<int>> &ans) {
        if(k == 1) {
            for(int i = cur; i <= 9; i++) {
                if(n == i) {
                    sub.push_back(i);
                    ans.push_back(sub);
                    return;
                }
            }
            return;
        } else {
            for(int i = cur; i <= 9; i++) {
                if(i < n) {
                    sub.push_back(i);
                    solve(k-1, n-i, i+1, sub, ans);
                    sub.pop_back();
                }
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(k, n, 1, sub, ans);
        return ans;
    }
};