/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

/*
continue with previous solution
when the two pointer point at same node
a new pointer is constructed from head
the pointer and the two-pointer keep going at same step
they will come together at the begining of the cycle

COOL! there are articles talk about the mechanism behind it
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
    ListNode *detectCycle(ListNode *head) {
        if (!(head)) return NULL;
	    ListNode *slow = head;
    	ListNode *fast = head;



    	while (slow != NULL && fast != NULL)
	    {
		    
		    slow = slow->next;
		    if(!(fast->next)) return NULL;
		    fast = fast->next->next;
		    if(fast == slow) break;

    	}
    	
    	if(slow == NULL || fast==NULL){return NULL;}
    	
    	ListNode *cnt = head;

    	while(cnt!=slow)
    	{
            cnt = cnt->next;
            slow = slow->next;
    	}
    	return cnt;

    	
    	
    }
};