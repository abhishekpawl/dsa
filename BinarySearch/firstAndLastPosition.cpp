/* https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ */
class Solution {
public:
    int first_occurence(vector<int>& nums, int tar) {
        int i = 0;
        int j = nums.size()-1;
        int mid, ans = -1;
        while(i <= j) {
            mid = i + (j-i)/2;
            if(nums[mid] == tar) {
                ans = mid;
                j = mid-1;
            } else if(nums[mid] < tar) {
                i = mid+1;
            } else {
                j = mid-1;
            }
        }
        return ans;
    }
    
    int last_occurence(vector<int>& nums, int tar, int f) {
        int i = f;
        int j = nums.size()-1;
        int mid, ans = -1;
        while(i <= j) {
            mid = i + (j-i)/2;
            if(nums[mid] == tar) {
                ans = mid;
                i = mid+1;
            } else if(nums[mid] < tar) {
                i = mid+1;
            } else {
                j = mid-1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first_occurence(nums, target);
        if(f == -1) return {-1, -1};
        int l = last_occurence(nums, target, f);
        return {f, l};
    }
};