/* https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/ */
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
        if(head->next->next == NULL) {
            ListNode *temp = head->next;
            head->next = NULL;
            delete temp;
            return head;
        }
        ListNode *f, *s;
        f = head;
        s = head;
        while(f->next->next != NULL && f->next->next->next != NULL) {
            s = s->next;
            f = f->next->next;
        }
        ListNode* temp = s->next;
        s->next = s->next->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
};