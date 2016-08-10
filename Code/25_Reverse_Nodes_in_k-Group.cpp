/********************************************************************************** 
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

* If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

* You may not alter the values in the nodes, only nodes itself may be changed.

* Only constant memory is allowed.

* For example,
* Given this linked list: 1->2->3->4->5

* For k = 2, you should return: 2->1->4->3->5

* For k = 3, you should return: 3->2->1->4->5
**********************************************************************************/

/********************************************************************************** 
* Using stack to handle the top k nodes, the feature of stack will just provide reverse operation
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || !head) return head;
        
        
        stack<ListNode *> stk;
        ListNode *start = head;
        ListNode *cnt = head;
        ListNode *result = nullptr;
        ListNode *body_tail = nullptr;
        
        while(cnt)
        {
            if(cnt)
            {
                stk.push(cnt);

                cnt = cnt->next;
                
            }
            
            if(stk.size()==k)
            {
                start = stk.top();

                if(!result) result = start;
                else body_tail->next = start;
                stk.pop();
                while(!stk.empty())
                {
                    start->next = stk.top();
                    start = start->next;
                    stk.pop();
                }
                body_tail = start;
                start->next = cnt;
            }
            if(!cnt && result==nullptr) return head;
        }
        
        return result;
    }
};