/*
Given a binary tree, find the leftmost value in the last row of the tree. 
Example 1:
Input:

    2
   / \
  1   3

Output:
1

Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7

Note: You may assume the tree (i.e., the given root node) is not NULL. 
*/

/*
BFS to the last line
or DFS maybe faster??
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
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*> que;
        que.push(root);
        return bfs(que);
    }
    
    int bfs(queue<TreeNode*>& que)
    {
        int res = que.front()->val;
        vector<TreeNode*> rec;
        while(!que.empty())
        {
            if(que.front()->left) rec.push_back(que.front()->left);
            if(que.front()->right) rec.push_back(que.front()->right);
            que.pop();
        }
        if(rec.empty()) return res;
        for(auto i:rec) que.push(i);
        return bfs(que);
    }
};