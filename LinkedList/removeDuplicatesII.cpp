/* https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/ */
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* distincthead = deleteDuplicates(head->next);
        if(distincthead == NULL && head->val != head->next->val) {
            head->next = distincthead;
            return head;
        }
        if(distincthead == NULL) {
            return distincthead;
        }
        if(head->val == distincthead->val) {
            return distincthead->next;
        }
        if(head->next->val == head->val) {
            return distincthead;
        }
        head->next = distincthead;
        return head;
    }
};