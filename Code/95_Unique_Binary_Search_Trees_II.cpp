/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*
write a subfunction to generate from a to b
basically sweep the number, recurrently call tree build function 
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return generateTree(1,n);
    }
    
    vector<TreeNode*> generateTree(int start, int end) {
        vector<TreeNode*> subtree;
        if(start > end) {subtree.push_back(nullptr); return subtree;}
        for(int k = start; k <= end; ++k)
        {
            vector<TreeNode*> left = generateTree(start,k-1);
            vector<TreeNode*> right = generateTree(k+1,end);
            for(auto i : left)
            {
                for(auto j : right)
                {
                    TreeNode *root = new TreeNode(k);
                    root->left = i;
                    root->right = j;
                    subtree.push_back(root);
                }
            }
            
        }
        return subtree;
    }
};