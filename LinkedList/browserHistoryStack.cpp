/* https://leetcode.com/problems/design-browser-history/ */
class BrowserHistory {
public:
    stack<string> cur;
    stack<string> next;
    BrowserHistory(string homepage) {
        cur.push(homepage);
    }
    
    void visit(string url) {
        cur.push(url);
        while(!next.empty()) {
            next.pop();
        }
    }
    
    string back(int steps) {
        while(cur.size() > 1 && steps--) {
            next.push(cur.top());
            cur.pop();
        }
        return cur.top();
    }
    
    string forward(int steps) {
        while(!next.empty() && steps--) {
            cur.push(next.top());
            next.pop();
        }
        return cur.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */