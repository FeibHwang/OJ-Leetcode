/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/*
Using a hash map to record the random pointer of each node
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList01(RandomListNode *head) {
        if(!(head)) return NULL;
         RandomListNode *init = new RandomListNode(0);
         RandomListNode *cnt = init;
         RandomListNode *orig = head->next;
         unordered_map<RandomListNode *,RandomListNode *> mp;
         
         cnt->label = head->label;
         if((head->random)) mp[cnt] = head->random;
         
         
         while(orig)
         {
             RandomListNode *body = new RandomListNode(0);
             body->label = orig->label;
             
             cnt->next = body; 
             cnt = cnt->next;
             if((orig->random))
                mp[cnt] = orig->random;
             orig = orig->next;
         }
         
         orig = head;
         cnt = init;
         while(orig)
         {
             for (unordered_map<RandomListNode *,RandomListNode *>::iterator i=mp.begin(); i!=mp.end(); i++)  
             {  
                 if (i->second == orig)  
                {  
                    i->first->random = cnt;
                    mp.erase(i);  
                }  
             } 
             orig = orig->next;
             cnt = cnt->next;
         }
         return init;
    }
    
    
    
    RandomListNode *copyRandomList(RandomListNode *head) {
         if(!(head)) return NULL;
         RandomListNode *init = new RandomListNode(0);
         RandomListNode *cnt = init;
         RandomListNode *orig = head->next;
         unordered_map<RandomListNode *,RandomListNode *> mp;
         cnt->label = head->label;
         mp[head] = cnt;
         
         while(orig)
         {
             RandomListNode *body = new RandomListNode(0);
             body->label = orig->label;
             
             cnt->next = body; 
             cnt = cnt->next;
             mp[orig] = cnt;
             orig = orig->next;
         }
         
         orig = head;
         cnt = init;
         
         while(orig)
         {
             if(orig->random)
                cnt->random = mp[orig->random];
             orig = orig->next;
             cnt = cnt->next;
         }
         return init;
    }
};