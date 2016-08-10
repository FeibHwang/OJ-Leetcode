/********************************************************************************** 
* Merge k sorted linked lists and return it as one sorted list. 
* Analyze and describe its complexity.
**********************************************************************************/

/********************************************************************************** 
* First realize merge two operation, then the rest is easy
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        for(int i = 1; i < lists.size(); ++i)
        {
            lists[0] = mergetwo(lists[0],lists[i]);
        }
        return lists[0];
    }
    
    ListNode *mergetwo(ListNode *list1, ListNode *list2)
    {
        ListNode *tmp = new ListNode(0);
        ListNode *l1 = list1;
        ListNode *l2 = list2;
        ListNode *result = tmp;
        
        while(l1&&l2)
        {
            if(l1->val <= l2->val)
            {
                tmp->next = l1;
                l1 = l1->next;
            }else{
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp -> next;
        }
        
        if(!l1)
        {
            tmp->next = l2;
        }else{
            tmp->next = l1;
        }
        
        tmp = result->next;
        result->next = NULL;
        delete result;
        return tmp;
        
    }
};