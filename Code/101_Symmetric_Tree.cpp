/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
*/

/*
mirror -> if the tree is rotated, it should be the same
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
    bool isSymmetric(TreeNode* root) {
        bool result = true;
        if((root))
        {
            root -> right = Rotated(root -> right);
            result = isSameTree(root->left, root->right);
            root -> right = Rotated(root -> right);
            return result;
        }
        else
            return result;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if(!p || !q) return false;
        else
            return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    
    TreeNode* Rotated(TreeNode* root)
    {
        if((root))
        {
            TreeNode* tmp1 = Rotated(root -> right);
            TreeNode* tmp2 = Rotated(root -> left);
            root -> left = tmp1;
            root -> right = tmp2;
            return root;
        }
        else
        return root;
    }
};