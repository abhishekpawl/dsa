/* https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1/# */
class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        stack<int> s;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(s.empty()) {
                ans.push_back(-1);
                s.push(a[i]);
            } else if(a[i] > s.top()) {
                ans.push_back(s.top());
                s.push(a[i]);
            } else {
                while(!s.empty() && a[i] <= s.top()) {
                    s.pop();
                }
                if(s.empty()) {
                    ans.push_back(-1);
                    s.push(a[i]);
                } else {
                    ans.push_back(s.top());
                    s.push(a[i]);
                }
            }
        }
        return ans;
    }
};