/* https://leetcode.com/problems/linked-list-cycle-ii/ */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *f, *s;
        f = head;
        s = head;
        while(f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;
            if(f == s) {
                break;
            }
        }
        if(f == NULL || f->next == NULL) {
            return NULL;
        }
        ListNode *ptr1, *ptr2;
        ptr1 = head;
        ptr2 = s;
        while(ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};