/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

/*
recurrent solution
key issue is split solution with/without root val
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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val == sum ? 1:0;
        return sumUp(root,sum,0) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    int sumUp(TreeNode* root, int sum, int pre)
    {
        if(!root) return 0;
        int curr = pre + root->val;
        return (curr == sum) + sumUp(root->left, sum, curr) + sumUp(root->right, sum, curr);
    }
};