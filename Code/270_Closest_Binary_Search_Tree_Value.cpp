/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
*/

/*
the function is garenteed to have one answer as long as the tree is not empty
so compare root->val, closestValue(root->left)->val, closestValue(root->right)->val, the answer is one of them
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
    int closestValue(TreeNode* root, double target) {
        double master = double(root->val);
        int left = INT_MAX, right = INT_MAX;
        if(!root->left && !root->right) return root->val;
        if(root->left) left = closestValue(root->left,target);
        if(root->right) right = closestValue(root->right,target);
        
        if(!root->left) return abs(master-target) <= abs((double)right-target) ? root->val:right;
        if(!root->right) return abs(master-target) <= abs((double)left-target) ? root->val:left;
        if(abs(master-target) <= abs((double)left-target) && abs(master-target) <= abs((double)right-target)) return root->val;
        else if(abs((double)left-target) <= abs(master-target) && abs((double)left-target) <= abs((double)right-target)) return left;
        return right;
    }
};