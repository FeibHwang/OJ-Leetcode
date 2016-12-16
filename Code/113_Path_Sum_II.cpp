/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

/*
similar to pathsum
maintain a vector for the value
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};
        if(!(root->left) && !(root->right))
        {
            if(root->val==sum)
            {
                vector<int> tmp = {sum};
                return {tmp};
            }else{
                return {};
            }
        }
        vector<vector<int>> rt;
        if((root->right) || (root->left)) 
        {
            rt = pathSum(root->right, sum-(root->val));
            vector<vector<int>> lft = pathSum(root->left, sum-(root->val));
            rt.insert(rt.end(),lft.begin(),lft.end());
        }
        for(int i = 0; i < rt.size(); ++i)
        {
            rt[i].insert(rt[i].begin(),root->val);
        }
        return rt;
    }
};