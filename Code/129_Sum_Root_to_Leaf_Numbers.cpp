/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

/*
recurrsive solution
not very efficient
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
    int sum;
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        sum = 0;
        int num = root->val;
        road_sum_record(root,num);
        return sum;
    }
    
    void road_sum_record(TreeNode* root, int num)
    {
        if(!(root->right) && !(root->left)) sum+=num;
        if(root->right) road_sum_record(root->right, 10*num + root->right->val);
        if(root->left) road_sum_record(root->left, 10*num + root->left->val);
    }
};