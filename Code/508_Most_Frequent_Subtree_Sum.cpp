/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order. 
Examples 1
Input: 
  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order. 

Examples 2
Input: 
  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once. 

Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer. 
*/

/*
find all possible sum
using hash map to track frequency
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return {};
        fq = -1;
        node_sum(root);
        vector<int> res;
        for(auto k:mp) if(k.second == fq) res.push_back(k.first);
        return res;
    }
    
private:
    int node_sum(TreeNode* root)
    {
        int l = 0, r = 0;
        if(root->left)
        {
            l = node_sum(root->left);
        }
        if(root->right)
        {
            r = node_sum(root->right); 
        }
        mp[l+r+root->val]++;
        fq = max(fq,mp[l+r+root->val]);
        return l+r+root->val;
    }
    
    int fq;
    unordered_map<int,int> mp;
};