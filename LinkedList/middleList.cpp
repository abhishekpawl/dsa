/* https://leetcode.com/problems/middle-of-the-linked-list/ */
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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow;
        ListNode* fast;
        slow = head;
        fast = head;
        while(fast->next) {
            if(fast->next->next) {
                fast = fast->next->next;
            } else if(fast->next) {
                fast = fast->next;
            }
            
            slow = slow->next;
        }
        return slow;
    }
};