/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

/*
Same to previous version
reverse the result
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result = levelOrder(root);
        reverse(result.begin(),result.end());
        return result;
    }
    
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