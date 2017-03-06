/*
Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1  
*/

/*
recursivelt call function on root->left,
original root->left ->left = original root -> right
original root->right = original root

cut down original root->left/right    <--very important !! or it's easy to cause infinite loop
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root==nullptr || root->left == nullptr) return root;
        TreeNode* myleft = root->left, *myright = root->right;

        TreeNode *newone = upsideDownBinaryTree(myleft);
        myleft->left = myright;
        myleft->right = root;
        root->right = nullptr;
        root->left = nullptr;
        return newone;

    }
};