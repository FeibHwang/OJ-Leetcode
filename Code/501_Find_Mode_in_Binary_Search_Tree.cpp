/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
Assume a BST is defined as follows: 
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2

return [2]. 
Note: If a tree has more than one mode, you can return them in any order. 
Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count). 
*/

/*
I use a hash map to count
so far I haven't find O(1) space solution
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
    vector<int> findMode(TreeNode* root) {
        int most = 0;
        unordered_map<int,int> cnt;
        dfs(root,cnt,most);
        vector<int> res;
        for(auto i:cnt)
        {
            if(i.second==most) res.push_back(i.first);
        }
        return res;
    }
    
    void dfs(TreeNode *root, unordered_map<int,int>& cnt, int &most)
    {
        if(root)
        {
            cnt[root->val]++;
            most = max(most,cnt[root->val]);
            dfs(root->left,cnt,most);
            dfs(root->right,cnt,most);
        }
    }
};