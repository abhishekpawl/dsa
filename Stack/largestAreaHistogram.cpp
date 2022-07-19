/* https://leetcode.com/problems/largest-rectangle-in-histogram/ */
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
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left, right;
        int n = heights.size();
        nsr(right, n, heights);
        nsl(left, n, heights);
        
        //for(int i = 0; i < n; i++) cout<<left[i]<<" ";
        //cout<<endl;
        //for(int i = 0; i < n; i++) cout<<right[i]<<" ";
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            int l = left[i];
            int r = right[i] == -1 ? n : right[i];
            maxi = max(maxi, (r - l - 1)*heights[i]);
        }
        
        return maxi;
    }
};