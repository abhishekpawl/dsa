/* https://leetcode.com/problems/longest-valid-parentheses/ */
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n <= 1) return 0;
        stack<pair<int, int>> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push({s[i], i});
            } else {
                if(s[i] == '}') {
                    if(st.size() == 0) {
                        st.push({s[i], i});
                    } else if(st.top().first == '{') {
                        st.pop();
                    } else {
                        st.push({s[i], i});
                    }
                } else if(s[i] == ']') {
                    if(st.size() == 0) {
                        st.push({s[i], i});
                    } else if(st.top().first == '[') {
                        st.pop();
                    } else {
                        st.push({s[i], i});
                    }
                } else if(s[i] == ')') {
                    if(st.size() == 0) {
                        st.push({s[i], i});
                    } else if(st.top().first == '(') {
                        st.pop();
                    } else {
                        st.push({s[i], i});
                    }
                }
            }
        }
        if(st.empty()) return n;
        int ans = INT_MIN;
        int prev = n;
        while(!st.empty()) {
            auto x = st.top();
            st.pop();
            cout<<prev<<" "<<x.second<<endl;
            int temp = prev - 1 - x.second;
            ans = max(ans, temp);
            prev = x.second;
            // if the partition is the last one we also need to check the length between starting and that partition
            if(st.empty()) {
                ans = max(ans, prev);
            }
        }
        return ans;
    }
};