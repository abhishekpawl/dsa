/* https://leetcode.com/problems/3sum-closest/ */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = -1;
        int mind = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n-2; i++) {
            int j = i + 1;
            int k = n-1;
            while(j < k) {
                int s = nums[i] + nums[j] + nums[k];
                int d = abs(target - s);
                if(d < mind) {
                    mind = d;
                    ans = s;
                }
                if(s == target) break;
                if(s < target) j++;
                if(s > target) k--;
            }
        }
        return ans;
    }
};