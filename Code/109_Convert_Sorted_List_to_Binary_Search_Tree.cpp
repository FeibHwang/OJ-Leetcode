/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
recurrent algorithm
*/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedList_Range(head,nullptr);
    }
        
        
    TreeNode * sortedList_Range(ListNode* head, ListNode* tail)
    {
        if(head==tail)
        {
            return NULL;
        }

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast!=tail && fast->next != tail)
        {

            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedList_Range(head,slow);
        root->right = sortedList_Range(slow->next,tail);
        return root;
    }
};