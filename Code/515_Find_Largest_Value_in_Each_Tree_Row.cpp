/*
You need to find the largest value in each row of a binary tree.
Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
*/

/*
Very BFS!! =_=
DFS also work
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        que.push(root);
        bfs(que,res);
        return res;
    }
    
    
    void bfs(queue<TreeNode*>& que,vector<int>& res)
    {
        if(que.empty() || que.front()==nullptr) return;
        int linemax = INT_MIN;
        vector<TreeNode*> tmp;
        while(!que.empty())
        {
            linemax = max(linemax,que.front()->val);
            if(que.front()->left) tmp.push_back(que.front()->left);
            if(que.front()->right) tmp.push_back(que.front()->right);
            que.pop();
        }
        res.push_back(linemax);
        if(!tmp.empty())
        {
            for(auto i:tmp)
                que.push(i);
        }
        bfs(que,res);
    }
};