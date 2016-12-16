/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

/*
pre-order traversal
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
    void flatten(TreeNode* root) {
        if(!root || (root && !root->left && !root->right)) return;
        else if(root && root->left && !root->right)
        {
            TreeNode *tmp = root->left;
            flatten(tmp);
            root->right = root->left;
            root->left = NULL;
            return;
        }
        else if(root && root->right && !root->left)
        {
            flatten(root->right);
            return;
        }

        TreeNode *l = root->left;
        TreeNode *r = root->right;
        flatten(l);flatten(r);
        while(l->right) l = l->right;
        root->right = root->left;
        root->left = NULL;
        l->right = r;
        return;
    }
};