/*
Sort a linked list using insertion sort.
*/

/*
insertion sort algorithm
not much to tell
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode *new_List = new ListNode(head->val);
        ListNode *count = new_List;
        ListNode *body = head->next;
        ListNode *before;
        while(body)
        {
            ListNode *new_body = new ListNode(body->val);
            count = new_List;
            if(count == new_List && body->val <= count->val)
            {
                new_body->next = new_List;
                new_List = new_body;
                body = body->next;
                count = new_List;
                continue;
            }
            
            while(count)
            {
                if(body->val <= count->val)
                {
                    before->next = new_body;
                    new_body->next = count;
                    break;
                }else{
                    before = count;
                    count = count->next;
                    if(!count && before->val <= body->val)
                    {
                        before->next = new_body;
                        break;
                    }
                }
            }
            body = body->next;
        }
        
        return new_List;
    }
};