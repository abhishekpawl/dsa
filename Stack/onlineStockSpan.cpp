/* https://leetcode.com/problems/online-stock-span/ */
class StockSpanner {
public:
    stack<pair<int, int>> s;
    StockSpanner() {
    }
    
    int next(int price) {
        int c = 1;
        if(s.empty()) {
            s.push({price, c});
        } else {
            while(!s.empty() && s.top().first <= price) {
                c += s.top().second;
                s.pop();
            }
            s.push({price, c});
        }
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */