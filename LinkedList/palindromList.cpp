/* https://leetcode.com/problems/palindrome-linked-list/ */
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
    ListNode* reverse(ListNode* head) {
        if(head == NULL  || head->next == NULL) {
            return head;
        }
        ListNode* temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return true;
        }
        ListNode *f, *s;
        f = head;
        s = head;
        while(f->next != NULL && f->next->next != NULL) {
            s = s->next;
            f = f->next->next;
        }
        s->next = reverse(s->next);
        ListNode *a, *b;
        a = head;
        b = s->next;
        while(b != NULL) {
            if(a->val != b->val) {
                return false;
            }
            a = a->next;
            b = b->next;
        }
        return true;
    }
};