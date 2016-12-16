/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/*
construct 2 new list
then connect then together
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
    ListNode* partition(ListNode* head, int x) {
        if(!(head) || !(head->next)) return head;
        
        
        ListNode *before = head;
        
        ListNode *result = new ListNode(x-1);
        result->next = head;
        ListNode *count = result;
        ListNode *greater = new ListNode(x);
        ListNode *greater_begin = greater;
        
        while(count->next)
        {
            if(count->next->val < x) count = count->next;
            else
            {
                //if(count->next->next)
                //{
                    greater->next = count->next;
                    count->next = count->next->next;
                    greater = greater->next;
                    greater->next = NULL;
                //}
            }
        }
        count->next = greater_begin->next;
        return result->next;
        
    }
};