/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
*/

/*
not much to tell
MEMORIZE THE ALGORITHM!!!!
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

//cool idea: postorder:left->right->root == reverse: root->right->left

    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        stack<TreeNode*> stk;
        TreeNode *cnt = root;
        
        vector<int> result;
        
        while(cnt || !stk.empty())
        {
            if(cnt)
            {
                stk.push(cnt);
                result.push_back(cnt->val);
                cnt = cnt->right;
            }else{
                cnt = stk.top();
                
                stk.pop();
                cnt = cnt->left;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};