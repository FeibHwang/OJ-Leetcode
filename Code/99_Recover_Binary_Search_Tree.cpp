/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

/*
not sure the exact principle, but pretty cool !
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
    //pretty cool algorithm!! remember this one:http://www.cnblogs.com/tgkx1054/archive/2013/05/24/3096830.html
    TreeNode *pre;
    TreeNode *wrong_one, *wrong_two;


    void recoverTree(TreeNode* root) {
        pre = wrong_one = wrong_two = nullptr;
        inorder(root);
        swap(wrong_one->val,wrong_two->val);
    }
    
    
    void inorder(TreeNode *root)
    {
        if(root->left) inorder(root->left);
        if(pre!=NULL&&pre->val > root->val)
        {
            if(!wrong_one) wrong_one = pre;
            wrong_two = root;
        }
        pre = root;
        if(root->right) inorder(root->right);
        
    }
    
};