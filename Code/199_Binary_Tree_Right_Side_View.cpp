/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/

/*
recurrsive algorithm
do it for root->left and root->right
you will get 2 array
the right side will overlap
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        if(!(root->left) && !(root->right)) return {root->val};
        if(!(root->left))
        {
            vector<int> result = {root->val};
            vector<int> tmp = rightSideView(root->right);
            result.insert(result.end(),tmp.begin(),tmp.end());
            return result;
        }
        if(!(root->right))
        {
            vector<int> result = {root->val};
            vector<int> tmp = rightSideView(root->left);
            result.insert(result.end(),tmp.begin(),tmp.end());
            return result;
        }
        vector<int> right = rightSideView(root->right);
        vector<int> left = rightSideView(root->left);
        
        if(left.size()>right.size())
            right.insert(right.end(),left.begin()+right.size(),left.end());
        right.insert(right.begin(),1,root->val);
        return right;
    }
};