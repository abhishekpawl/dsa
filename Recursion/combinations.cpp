/* https://leetcode.com/problems/combinations/ */
class Solution {
public:
    void solve(int i, int n, int k, vector<int> &temp, vector<vector<int>> &ans) {
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if(n == 0) return;
        temp.push_back(i);
        solve(i+1, n-1, k, temp, ans);
        temp.pop_back();
        solve(i+1, n-1, k, temp, ans);
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, n, k, temp, ans);
        return ans;
    }
};