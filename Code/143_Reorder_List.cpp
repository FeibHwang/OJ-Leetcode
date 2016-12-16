/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
A naive way: record the value in vector, reassign the list
Another proper way:
use stack to record every list node
then from list head keep connect to stack top, until stack top is equal to the list tail.
*/

class Solution {
public:
    void reorderList01(ListNode* head) {
        if(!(head)||!(head->next)||!(head->next->next)) return;
        
        vector<int> rec;
        ListNode *b = head;
        while(b)
        {
            rec.push_back(b->val);
            b = b->next;
        }
        
        b = head->next;
        int length = rec.size();
        int cnt = 1;
        
        while(b)
        {
            if(cnt%2==1)
            {
                b->val = rec[--length];
            }else{
                b->val = rec[cnt/2];
            }
            cnt++;
            b = b->next;
        }
    }
};


void reorderList(ListNode* head) {
        if(!(head)||!(head->next)||!(head->next->next)) return;
        
        stack<ListNode*> stk;
        ListNode *cnt = head;
        while(cnt)
        {
            stk.push(cnt);
            cnt = cnt->next;
        }
        
        cnt = head;
        
        while(!stk.empty() && cnt->next != stk.top())
        {
            ListNode *tmp = cnt->next;
            cnt->next = stk.top();
            stk.top()->next = tmp;
            cnt = tmp;
            stk.pop();
            if(!stk.empty() && cnt == stk.top())
            {
                cnt->next = NULL;
                return;
            }
        }
        cnt->next->next = NULL;
    }