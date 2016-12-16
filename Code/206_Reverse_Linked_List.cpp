/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/


/*
directly reverse, not much to tell
*/


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
    ListNode* reverseList(ListNode* head) {
        if(!(head) || !(head->next)) return head;
        ListNode *h = head;
        ListNode *t = head->next;
        head->next = NULL;
        if(!(t->next)) {
            t->next = h;
            return t;
        }
        while(t->next)
        {
            ListNode *tmp = t->next;
            t->next = h;
            h = t;
            t = tmp;
        }
        t->next = h;
        return t;
    }
};