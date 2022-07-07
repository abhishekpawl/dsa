/* https://leetcode.com/problems/top-k-frequent-words/ */
#define pis pair<int, string>

class Solution {
    struct comp{
        bool operator()(pis &a, pis &b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;     
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> freq;
        for(int i = 0; i < words.size(); i++) {
            freq[words[i]]++;
        }
        priority_queue<pis, vector<pis>, comp> minheap;
        for(auto ele: freq) {
            minheap.push({ele.second, ele.first});
            if(minheap.size() > k) minheap.pop();
        }
        vector<string> ans;
        while(minheap.size()) {
            ans.push_back(minheap.top().second);
            minheap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};