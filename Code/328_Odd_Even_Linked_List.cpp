/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
*/

/*
construct 2 list, and connect
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
    ListNode* oddEvenList(ListNode* head) {
        if(!(head) || !(head->next) || !(head->next->next)) return head;
        
        ListNode *even = head->next;
        ListNode *odd = head;
        ListNode *hlf = even;
        
        while(true)
        {
            if(even->next)
            {
                odd->next = even->next;
                odd = even->next;
            }
            if(odd->next)
            {
                even->next = odd->next;
                even = odd->next;
            }
            if(!(odd->next)&&even->next)
            {
                even->next = odd->next;
                odd->next = hlf;
                return head;
            }
            if(!(even->next)&&odd->next)
            {
                odd->next = hlf;
                return head;
            }
        }
    }
};