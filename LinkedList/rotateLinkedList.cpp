/* https://leetcode.com/problems/rotate-list/ */
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        ListNode *trav = head, *f = head, *s = head;
        int c{};
        while(trav != NULL) {
            c++;
            trav = trav->next;
        }
        k = (k > c) ? k % c : k;
        int temp_k = k;
        while(temp_k--) {
            s = (s->next) ? s->next : head;
        }
        while(s->next != NULL) {
            f = (f->next) ? f->next : head;
            s = (s->next) ? s->next : head;
        }
        s->next = head;
        ListNode *newhead = f->next;
        f->next = NULL;
        return newhead;
    }
};