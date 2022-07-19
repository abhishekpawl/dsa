/* https://leetcode.com/problems/maximal-rectangle/ */
class Solution {
public:
    void nsr(vector<int> &right, int n, vector<int> &heights) {
        stack<int> s;
        
        for(int i = n-1; i >= 0; i--) {
            if(s.empty()) {
                right.push_back(-1);
            } else {
                while(!s.empty() && heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                if(s.empty()) {
                    right.push_back(-1);
                } else {
                    right.push_back(s.top());
                }
            }
            s.push(i);
        }
        reverse(right.begin(), right.end());
        return;
    }
    
    void nsl(vector<int> &left, int n, vector<int> &heights) {
        stack<int> s;
        
        for(int i = 0; i < n; i++) {
            if(s.empty()) {
                left.push_back(-1);
            } else {
                while(!s.empty() && heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                if(s.empty()) {
                    left.push_back(-1);
                } else {
                    left.push_back(s.top());
                }
            }
            s.push(i);
        }
        return;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> heights, left, right;
        int maxi = -1;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    heights.push_back((int)(matrix[0][j]-'0'));
                } else {
                    if(matrix[i][j] == '0') {
                        heights[j] = 0;
                    } else {
                        heights[j] += 1;
                    }
                }
            }
            nsr(right, n, heights);
            nsl(left, n, heights);
            for(int j = 0; j < n; j++) {
                int l = left[j];
                int r = right[j] == -1 ? n : right[j];
                maxi = max(maxi, (r - l - 1)*heights[j]);
            }
            left.clear();
            right.clear();
        }
        
        return maxi;
    }
};