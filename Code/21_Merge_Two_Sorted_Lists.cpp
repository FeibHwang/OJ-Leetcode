/********************************************************************************** 
* Merge two sorted linked lists and return it as a new list. 
* The new list should be made by splicing together the nodes of the first two lists.
**********************************************************************************/

/********************************************************************************** 
last step of merge sort algorithm
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *list1 = (l1->val < l2->val)?l1:l2;
        ListNode *list2 = (l1->val < l2->val)?l2:l1;
        ListNode *result = new ListNode(0);
        ListNode *head = result; 

        while((list1) && (list2))
        {
            if(list1->val < list2->val)
            {
                result->next = list1;
                list1 = list1->next;
            }else{
                result->next = list2;
                list2=list2->next;
            }
            result = result->next;
            
        }
        if(list1) result->next = list1;
        if(list2) result->next = list2;

        
        return head->next;
    }
};