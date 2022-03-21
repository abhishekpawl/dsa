/* https://leetcode.com/problems/remove-nth-node-from-end-of-list/ */
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) {
            return head;
        }
        ListNode* temp = head;
        int l{};
        // length of the list
        while(temp != NULL) {
            l++;
            temp = temp->next;
        }
        // WHEN Nth node from the end of N-sized list (i.e. first node)
        if(n == l || n % l == 0) {
            ListNode* d = head;
            head = head->next;
            return head;
        }
        // Discarding the repetitive iterations
        if(n > l) {
            n = n % l;
        }
        ListNode *f, *s;
        f = head;
        s = head;
        while(n--) {
            s = s->next;
        }
        while(s->next != NULL) {
            f = f->next;
            s = s->next;
        }
        temp = f->next;
        f->next = f->next->next;
        return head;
    }
};