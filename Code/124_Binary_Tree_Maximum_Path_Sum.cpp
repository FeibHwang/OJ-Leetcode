/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

/*
DFS solution
keep updating the max value
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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxtoroot(root,res);
        return res;
        
    }
    
    int maxtoroot(TreeNode *root, int &re)
    {
        if(!root) return 0;
        int leftmax = maxtoroot(root->left, re);
        int rightmax = maxtoroot(root->right, re);
        leftmax = (leftmax>0)*leftmax;
        rightmax = (rightmax>0)*rightmax;
        re = leftmax + rightmax + root->val > re ? leftmax + rightmax + root->val : re;
        return root->val + max(leftmax,rightmax);
    }
    
};