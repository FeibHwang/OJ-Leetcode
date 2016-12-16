/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
first order triversal
*/

class Solution {
public:
    int maxDepth01(TreeNode* root) {
        if(!(root)) return 0;
        if(!(root->left)&& !(root->right)) return 1;
        int lft = maxDepth(root->left);
        int rt = maxDepth(root->right);
        return (lft>rt)?(1+lft):(1+rt);
        
    }
    
    int maxDepth(TreeNode* root) {
        if(!(root)) return 0;
        int count = 1;
        int depth = 0;
        queue<TreeNode *> nodeStack;
        nodeStack.push(root);
        TreeNode* search;
        while(!nodeStack.empty())
        {
            search = nodeStack.front();
            nodeStack.pop();
            count--;
            if(search->right){
            nodeStack.push(search->right);  //先将右子树压栈
            }
            if(search->left){
            nodeStack.push(search->left);  //再将左子树压栈
            }
            
            if (count == 0) {
             depth ++;
             count = nodeStack.size();
        }
        }
        return depth;
    }

};