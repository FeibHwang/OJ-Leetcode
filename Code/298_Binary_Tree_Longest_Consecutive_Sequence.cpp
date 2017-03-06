/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/

/*
since it's BST, using DFS literate 
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
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int cnt = root->val;
        return max(dfs(root->left,1,cnt),dfs(root->right,1,cnt));
    }
    
    int dfs(TreeNode* root, int acc ,int cnt)
    {
        if(!root)
        {
            return acc;
        }else{
            
            acc = root->val-1 == cnt ? acc+1:1;
            cnt = root->val;
            int left = dfs(root->left,acc,cnt);
            int right = dfs(root->right,acc,cnt);
            return max(max(left,right),acc);
        }
    }
};