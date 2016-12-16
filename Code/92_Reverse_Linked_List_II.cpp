/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
a naive approach: find the pointer toward mth and nth list position
cut of, perform reversList, connect back
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

	ListNode* start = head;
	ListNode* end = head;
	ListNode* rec = head;
	int length = 0;
	while (rec) { length++; rec = rec->next; }
	rec = head;

	if (m == n) return head;
	if (m >= length) return head;
	int cnt = 1;

	while (cnt <= n)
	{
		if (cnt < m) {
			rec = start;
			start = start->next;
		}
		if (cnt < length && cnt < n)
			end = end->next;
		cnt++;
	}

	ListNode *tail = end->next;
	end->next = NULL;

	if (rec == start)
	{
		head = reversList(start);
	}
	else {
		rec->next = reversList(start);
	}
	

	end = (rec == start)?head:start;
	while (end->next) end = end->next;
	end->next = tail;

	return head;
}
    
    ListNode* reversList(ListNode *head)
    {
	    if (!(head) || !(head->next)) return head;
	    else if (!(head->next->next))
	    {
		    ListNode* tail = head->next;
		    head->next = NULL;
		    tail->next = head;
		    return tail;
	    }
	    else
	    {
		    ListNode* pre = head;
		    ListNode* cur = pre->next;
		    pre->next = NULL;   // set tail
		    ListNode* post = cur->next;
		    while (post)
		    {
		    	cur->next = pre;
			    pre = cur;
			    cur = post;
			    post = post->next;
		    }
		    cur->next = pre;
		    return cur;
	    }
}
};