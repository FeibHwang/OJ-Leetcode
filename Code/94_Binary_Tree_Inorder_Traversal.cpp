/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
non-recursive solution:
using stack to preserve previous node
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *cnt = root;
        vector<int> result;
        
        while(cnt || !stk.empty())
        {
            if(cnt)
            {
                stk.push(cnt);
                cnt = cnt->left;
            }else{
                cnt = stk.top();
                result.push_back(cnt->val);
                stk.pop();
                cnt = cnt->right;
            }
        }
        return result;
    }
};