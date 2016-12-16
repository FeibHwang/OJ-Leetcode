/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
*/

/*
first intrival of BST, the number will be non-decreasing
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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!(root->left) && !(root->right)) return true;
        
        stack<TreeNode *> stk;
        TreeNode *cnt = root;
        
        TreeNode *value = nullptr;
        
        while(cnt || !stk.empty())
        {
            if(cnt)
            {
                stk.push(cnt);
                cnt = cnt->left;
            }else{
                cnt = stk.top();
                
                if(!value) value = cnt;
                else{
                    if(value->val >= cnt->val)
                        return false;
                    else{
                        value = cnt;
                    }
                }
                
                stk.pop();
                cnt = cnt->right;
            }
        }
        return true;
    }
};