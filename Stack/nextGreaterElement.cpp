/* https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1/ */
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long> s;
        vector<long long> ans;
        for(int i = n-1; i >= 0; i--) {
            if(s.empty()) {
                ans.push_back(-1);
                s.push(arr[i]);
            } else if(arr[i] < s.top()) {
                ans.push_back(s.top());
                s.push(arr[i]);
            } else {
                while(!s.empty() && s.top() < arr[i]) {
                    s.pop();
                }
                if(s.empty()) {
                    ans.push_back(-1);
                    s.push(arr[i]);
                } else {
                    ans.push_back(s.top());
                    s.push(arr[i]);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};