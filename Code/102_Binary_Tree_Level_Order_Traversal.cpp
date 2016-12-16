/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/*
using 2 queue to preserve each level elements
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result = {};
        vector<int> resultmp;
        if(!(root)) return result;
        
        queue<TreeNode *> q1;
        q1.push(root);
        
        while(!q1.empty())
        {
            queue<TreeNode *>q2;
            
            while(!q1.empty())
            {
                TreeNode *tmp = q1.front();
                q1.pop();
                resultmp.push_back(tmp->val);
                if(tmp->left) q2.push(tmp->left);
                if(tmp->right) q2.push(tmp->right);
            }
            result.push_back(resultmp);
            resultmp.clear();
            q1=q2;
        }
        return result;
    }
};