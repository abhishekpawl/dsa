/* https://leetcode.com/problems/search-a-2d-matrix/ */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m, n;
        m = matrix.size();
        n = matrix[0].size();
        
        if(m == 1 && n == 1) {
            return matrix[0][0] == target;
        }
        
        int row = 0;
        
        if(m > 1) {
            // binary search in the first column
            int l = 0, r = m-1;
            while(l < r) {
                int mid = l + (r-l)/2;
                if(matrix[mid][0] == target) return true;
                else if(matrix[mid][0] < target) {
                    if(mid == m-1) {
                        l = m-1;
                        break;
                    } else {
                        if(matrix[mid+1][0] == target) {
                            return true;
                        } else if(matrix[mid+1][0] < target) {
                            l = mid+1;
                        } else {
                            l = mid;
                            break;
                        }
                    }
                }
                else if(matrix[mid][0] > target) r = mid-1;
            }

            row = l;
        }
        
        // binary search in the selected row
        int l = 0;
        int r = n-1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target) l = mid+1;
            else r = mid-1;
        }
        
        return false;
    }
};