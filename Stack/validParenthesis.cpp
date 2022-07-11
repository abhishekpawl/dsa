/* https://leetcode.com/problems/valid-parentheses/ */
class Solution {
public:
    bool isValid(string S) {
        int n = S.size();
        if(n & 1) return false;
        stack<char> s;
        for(char ch: S) {
            if(ch == '(' || ch == '[' || ch == '{') {
                s.push(ch);
            } else {
                if(ch == ')') {
                    if(s.empty()) {
                        return false;
                    } else if(s.top() == '(') {
                        s.pop();
                    } else {
                        s.push(ch);
                    }
                } else if(ch == ']') {
                    if(s.empty()) {
                        return false;
                    } else if(s.top() == '[') {
                        s.pop();
                    } else {
                        s.push(ch);
                    }
                } else if(ch == '}') {
                    if(s.empty()) {
                        return false;
                    } else if(s.top() == '{') {
                        s.pop();
                    } else {
                        s.push(ch);
                    }
                }
            }
        }
        return s.empty();
    }
};