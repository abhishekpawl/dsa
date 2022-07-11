/* https://leetcode.com/problems/3sum/ */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        for(int i = 0; i < n-2; i++) {
            int target = -nums[i];
            int j = i+1;
            int k = nums.size()-1;
            while(j < k) {
                if(nums[j] + nums[k] == target) {
                    if(s.find({nums[i], nums[j], nums[k]}) == s.end()) {
                        s.insert({nums[i], nums[j], nums[k]});
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                    j++;
                    k--;
                } else if(nums[j] + nums[k] > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};