/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*/

/*
pretty straight forward way
is there any faster solution?
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
    void deleteNode(ListNode* node) {
        while (node->next)
	    {
	    	node->val = node->next->val;
	    	ListNode *tmp = node;
	    	node = node->next;
	    	if (!(node->next))
	    	{
	    		tmp->next = NULL;
	    		break;
	    	}
    	}
    }
};