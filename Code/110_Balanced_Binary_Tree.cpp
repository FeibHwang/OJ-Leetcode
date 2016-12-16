/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/*
hight function return the max height of a tree
isBalanced(tree) = isBalanced(tree->left) AND isBalanced(tree->right) AND abs(hight(tree->left)-hight(tree->right))<=1
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int left_depth = hight(root->left);
        int right_depth = hight(root->right);

        return isBalanced(root->left) && isBalanced(root->right) && abs(left_depth - right_depth)<=1;
    }
    
    int hight(TreeNode* root) {
        if (root == NULL) return 0; 
        int left = hight(root->left);
        int right = hight(root->right);
        
        if(left < 0 ||right < 0 || abs(left-right)>1) return -1;    // <----important
        else return max(left, right) + 1;  //why???
    }
    
};