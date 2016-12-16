/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/*
key issue is that k might be larger than list length
so we need to calculate list langth, and mod k to get real k
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !(head->next) || k==0) return head;
        int count = 1;
        ListNode *c = head;
        while(c->next)
        {
            count++;
            c = c->next;
        }
        
        ListNode* tail = c;
        int realc = count - k%count;
        c = head;
        while(realc > 1)
        {
            c = c->next;
            realc--;
        }
        
        tail->next = head;
        ListNode *result = c->next;
        c->next = NULL;
        return result;
    }
};