/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

/*
Here I use the stack
Maybe there is a better solution
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> sl1;
        stack<int> sl2;
        while(l1) {sl1.push(l1->val);l1 = l1->next;}
        while(l2) {sl2.push(l2->val);l2 = l2->next;}
        int cnt = 0;
        ListNode *res = nullptr;
        while(!sl1.empty() || !sl2.empty())
        {
            int add1 = 0;
            if(!sl1.empty())
            {
                add1 = sl1.top();
                sl1.pop();
            }
            int add2 = 0;
            if(!sl2.empty())
            {
                add2 = sl2.top();
                sl2.pop();
            }
            ListNode *head = new ListNode((add1+add2+cnt)%10);
            cnt = (add1+add2+cnt)/10;
            head->next = res;
            res = head;
        }
        if(cnt > 0) {
            ListNode *head = new ListNode(cnt);
            head->next = res;
            res = head;
        }
        return res;
    }
};