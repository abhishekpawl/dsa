/* https://leetcode.com/problems/merge-k-sorted-lists/ */
/* Heap approach */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class cmp {
public:
    bool operator() (ListNode *l1, ListNode *l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        ListNode *s, *e;
        s = new ListNode(-1);
        e = s;
        int flag = 0;
        while(!pq.empty()) {
            e->next = pq.top();
            e = e->next;
            pq.pop();
            if(e->next) {
                pq.push(e->next);
            }
        }
        return s->next;
    }
};