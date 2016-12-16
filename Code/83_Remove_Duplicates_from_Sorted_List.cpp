/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
if(pointer->next->val == pointer->val) pointer->next = pointer->next->next
pretty bruttal way
*/

class Solution {
public:
    ListNode* deleteDuplicates02(ListNode* head) {
        unordered_map<int,bool>mp;
        ListNode *cnt; cnt = head;
        
        if(head==NULL || head->next==NULL) return head;
        mp[cnt->val]=true;
        
        while(cnt->next)
        {
            if(mp.find(cnt->next->val)==mp.end())
            {
                mp[cnt->next->val]=true;
            }else{
                    cnt->next = cnt->next->next;
                    continue;
            }
            cnt = cnt->next;
        }
        return head;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next)) return head;
        
        ListNode *start = head;
        
        while(start->next)
        {
            if(start->next->val != start->val) start = start->next;
            else
            {
                start->next = start->next->next;
            }
        }
        
        return head;
    }
};