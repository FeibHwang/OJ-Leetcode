/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

Hint:

Consider implement these two helper functions:
getPredecessor(N), which returns the next smaller node to N.
getSuccessor(N), which returns the next larger node to N.
Try to assume that each node has a parent pointer, it makes the problem much easier.
Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
You would need two stacks to track the path in finding predecessor and successor node separately.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
maintian a size k containner, I use deque here
iterate tree in pre-order, the number goes increased
push k value into deque, then get another, compare
*/

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> rec = firstorder(root);
        
        while(rec.size()>k)
        {
            if(abs(rec.front()-target) > abs(rec.back()-target)) rec.pop_front();
            else rec.pop_back();
        }
        vector<int> res(rec.begin(),rec.end());
        return res;
    }
    
    deque<int> firstorder(TreeNode* root)
    {
        TreeNode *cnt = root;
        deque<int> res;
        stack<TreeNode *> stk;
        while(cnt || !stk.empty())
        {
            if(cnt)
            {
                stk.push(cnt);
                cnt = cnt->left;
            }else{
                cnt = stk.top();
                res.push_back(cnt->val);
                cnt = cnt->right;
                stk.pop();
            }
        }
        return res;
    }
};