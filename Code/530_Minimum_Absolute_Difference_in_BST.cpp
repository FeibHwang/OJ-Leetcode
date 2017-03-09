/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
Example: 
Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
*/

/*
using pre-traversal
the iterated value is sorted,
track previous value, maintain min abs of previous value - iterated value
update previous value
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
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> hold;
        int rec = INT_MAX, prev = INT_MAX;
        stack<TreeNode*> stk;
        TreeNode *cnt = root;
        while(!stk.empty() || cnt)
        {
            if(cnt)
            {
                stk.push(cnt);
                cnt = cnt->left;
            }else{
                cnt = stk.top();
                stk.pop();
                hold.push_back(cnt->val);
                if(prev!=INT_MAX) rec = min(rec,abs(prev-cnt->val));
                prev = cnt->val;
                cnt = cnt->right;
            }
        }
        return rec;
    }
    

};