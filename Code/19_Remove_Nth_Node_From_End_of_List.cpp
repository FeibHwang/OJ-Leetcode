/********************************************************************************** 
* Given a linked list, remove the nth node from the end of list and return its head.

* For example,

      Given linked list: 1->2->3->4->5, and n = 2.

      After removing the second node from the end, the linked list becomes 1->2->3->5.
**********************************************************************************/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* through; through=head;
        while(through){count++;through=through->next;}
        
        if(count==1){return NULL;}
        
        if(--count - n < 0) {return head->next;}
        count = count - n;
        
        through = head;
        while(count>0)
        {
            through = through->next;
            --count;
        }
        through->next = through->next->next;
        
        return head;
    }
};