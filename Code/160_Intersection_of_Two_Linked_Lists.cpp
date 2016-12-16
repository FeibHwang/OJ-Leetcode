/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/


/*
First calculate the length of two list
find the difference, the pointer to the longer one move difference step, then two pointer move at same speed
when they are equal, it's when they intersect
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // idea: connect c3 with a1
class Solution {
public:
    ListNode *getIntersectionNode01(ListNode *headA, ListNode *headB) {
        if(!(headA) || !(headB)) return NULL;
        
        int tailcnt = 0;
        
        ListNode *ct = headA;
        while(ct->next) ct = ct->next;
        ct->next = headB;
        
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        
        while(p1 && p2)
        {
            p1 = p1->next;
            if(!(p2->next))
                p2 = p2->next->next;
            if(p1 == p2) break;
            if(!(p1->next)||!(p2->next)) 
            {
                ct->next = NULL;
                return NULL;
            }
        }
        
        p2 = headA;
        while(p2 != p1)
        {
            p1=p1->next;
            p2=p2->next;
        }
        
        ct->next = NULL;
        return p1;
        
        
    }
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
        int lengthA = 1;
        int lengthB = 1;
        ListNode *cntA = headA;
        ListNode *cntB = headB;
        
        while(cntA){lengthA++; cntA = cntA->next;}
        while(cntB){lengthB++; cntB = cntB->next;}
        
        if(cntA!=cntB) return NULL;
        
        if(lengthA > lengthB)
        {
            cntA = headA;   
            cntB = headB;
        }else{
            cntA = headB;
            cntB = headA;
        }
        
        int dif = abs(lengthA - lengthB);
        
        while(dif>0)
        {
            cntA = cntA->next;
            dif--;
        }
        
        while(cntA != cntB && cntA && cntB)
        {
            cntA = cntA->next;
            cntB = cntB->next;
        }
        return cntA;
    }

    
};