/* https://leetcode.com/problems/lru-cache/ */
class LRUCache {
public:
    unordered_map<int, int> m;
    unordered_map<int, list<int>::iterator> address;
    list<int> l;
    int siz;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        siz = 0;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) {
            return -1;
        }
        list<int>::iterator it = address[key];
        l.erase(it);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            l.erase(address[key]);
            m.erase(key);
            address.erase(key);
            siz--;
        }
        if(siz == cap) {
            int del = l.back();
            l.erase(address[del]);
            address.erase(del);
            m.erase(del);
            siz--;
        }
        l.push_front(key);
        address[key] = l.begin();
        m[key] = value;
        siz++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */