/********************************************************************************** 
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.

* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
**********************************************************************************/

/********************************************************************************** 
* Basic Idea:
* Just like basic full adder
* Here I first ensure the two list has the same length by adding additional 0 which won't affect the representing value of the list
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *count1 = l1;
        ListNode *count2 = l2;
        
        while(count1->next || count2->next)
        {
            if(count1->next && count2->next)
            {
                count1=count1->next;
                count2=count2->next;
                continue;
            }
            
            if(!(count1->next) && count2->next)
            {
                ListNode *new_body = new ListNode(0);
                count1->next = new_body;
                continue;
            }
            
            if(count1->next && !(count2->next))
            {
                ListNode *new_body = new ListNode(0);
                count2->next = new_body;
                continue;
            }
        }
        
        int c = 0;
        count1 = l1;
        count2 = l2;
        while(count1)
        {
            count2->val = count2->val + count1->val + c;
            
            if(count2->val >= 10)
            {
                count2->val -= 10;
                c = 1;
            }else{
                c = 0;
            }
            
            if(!(count1->next))
            {
                if(c==0) return l2;
                else{
                    ListNode *tail = new ListNode(1);
                    count2->next = tail;
                    return l2;
                }
            }
            
            count1=count1->next;
            count2=count2->next;
        }
        
        return NULL;
    }
};