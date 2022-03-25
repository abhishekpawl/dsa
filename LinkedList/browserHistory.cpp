/* https://leetcode.com/problems/design-browser-history/ */
class BrowserHistory {
public:
    
    list<string> browserHistory;
    list<string> :: iterator it;
    
    BrowserHistory(string homepage) {
        browserHistory.push_back(homepage);
        it = browserHistory.begin();
    }
    
    void visit(string url) {
        auto del = it;
        del++;
        browserHistory.erase(del, browserHistory.end());
        browserHistory.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(it != browserHistory.begin() && steps--) {
            it--;
        }
        return *it;
    }
    
    string forward(int steps) {
        while(it != (--browserHistory.end()) && steps--) {
            it++;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */