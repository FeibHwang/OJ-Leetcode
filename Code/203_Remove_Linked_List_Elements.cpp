/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

/*
not much to explain
pay attention to the head->val, it's easy to ignore
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!(head)) return head;
        if(!(head->next))
        {
            if(head->val==val) return head->next;
            else return head;
        }
        
        
        ListNode *t = head;
        
        while(t->next)
        {
            if(t->next->val == val)
            {
                if(!(t->next->next))
                {
                    t->next = NULL;
                    return (head->val==val)?head->next:head;
                }else{
                    t->next = t->next->next;
                    continue;
                }
            }
            
            t = t->next;
        }
        return (head->val==val)?head->next:head;
    }
};