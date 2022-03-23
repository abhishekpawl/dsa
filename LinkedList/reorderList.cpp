/* https://leetcode.com/problems/reorder-list/ */
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
    ListNode* reverse(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return;
        }
        ListNode *f, *s;
        f = head;
        s = head;
        while(f->next != NULL && f->next->next != NULL) {
            s = s->next;
            f = f->next->next;
        }
        s->next = reverse(s->next);
        ListNode *a, *b, *temp_a, *temp_b;
        a = head;
        b = s->next;
        while(b != NULL) {
            if(a->next == b) {
                return;
            }
            temp_a = a->next;
            temp_b = b->next;
            a->next = b;
            b->next = temp_a;
            s->next = temp_b;
            a = temp_a;
            b = temp_b;
        }
        return;
    }
};