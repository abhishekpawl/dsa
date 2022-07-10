class MinStack {
    stack<int> s;
    int ret;
    
    void work() {
        if(s.empty()) return;
        int x = s.top();
        s.pop();
        ret = min(ret, x);
        work();
        s.push(x);
    }
    
public:
    MinStack() {
        ret = INT_MIN;
    }
    
    void push(int val) {
        s.push(val);
        if(ret == INT_MIN || ret >= val) {
            ret = val;
        }
    }
    
    void pop() {
        int temp = s.top();
        s.pop();
        if(temp == ret) {
            ret = INT_MAX;
            work();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ret;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */