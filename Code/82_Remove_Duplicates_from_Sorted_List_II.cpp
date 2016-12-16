/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
pretty much the same with Remove Duplicates from Sorted List
but this time, use a vector to record the duplicated value
after delete duplicate
delete the value recorded
*/

class Solution {
public:
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next)) return head;
        
        ListNode *start = head;
        vector<int> rec;
        
        while(start->next)
        {
            if(start->next->val != start->val) start = start->next;
            else
            {
                rec.push_back(start->val);
                start->next = start->next->next;
            }
        }
        
        start = head;
        while(start->next)
        {
            if(find(rec.begin(),rec.end(),start->next->val)!=rec.end())
            {
                start->next = start->next->next;
                continue;
            }
            start = start->next;
        }
        
        if(find(rec.begin(),rec.end(),head->val)!=rec.end()) return head->next;
        return head;
    }
};