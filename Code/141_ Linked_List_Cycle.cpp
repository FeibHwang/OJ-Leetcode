/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/


/*
using two pointer to head
one goes one step at a time
one goes two step at a time
if there is a loop, two pointer will pointing at same node sooner or later
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
    bool hasCycle(ListNode *head) {
        
        if(!(head)) return false;
        if((head)&&!(head->next)) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        
        while(slow != fast)
        {
            if(!(fast->next)) return false;
            if(!(fast->next->next)) return false;
            fast = fast ->next -> next;
            slow = slow->next;
        }
        return true;
    }
};