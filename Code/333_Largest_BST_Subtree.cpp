/*
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
Hint:

You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?
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

/*
I write a is valid BST function, apply to the root, if is, return record number
or reurn max(largestBSTSubtree(root->left),largestBSTSubtree(root->right))
O(nlogn), may be there is a faster way? 
I am thinking directly record pre-travel of the tree to see if there are some feature of BST subtree
*/

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if(isValidBST(root)>-1) return isValidBST(root);
        else return max(largestBSTSubtree(root->left),largestBSTSubtree(root->right));
    }
    
    int isValidBST(TreeNode* root) {
        if(!root) return 0;
        stack<TreeNode* > stk;
        TreeNode *body = root;
        TreeNode *value = nullptr;
        vector<int> rec;
        int cnt = 0;
        while(body || !stk.empty())
        {
            if(body)
            {
                stk.push(body);
                body = body->left;
                cnt++;
            }else{
                body = stk.top();
                if(!value) value = body;
                else{
                    if(body->val <= value->val) return -1;
                    else value = body;
                }
                rec.push_back(body->val);
                stk.pop();
                body = body->right;
            }
        }
        return cnt;
    }
};