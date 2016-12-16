/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/


/*
not much to tell
MEMORIZE THE ALGORITHM!!!!
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

    //effeciency:low
    vector<int> preorderTraversal01(TreeNode* root) {
        if(!(root)) return {};
        vector<int> result;
        if(!(root->left) && !(root->right))
        {
            result.push_back(root->val);
            return result;
        }
        vector<int> head = {root->val};
        vector<int> left = {};
        vector<int> right = {};
        if(root->left)
            left = preorderTraversal(root->left);
        if(root->right)
            right = preorderTraversal(root->right);
            
        head.insert(head.end(),left.begin(),left.end());
        head.insert(head.end(),right.begin(),right.end());
        return head;
    }
    
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(!(root)) return {};
        stack<TreeNode*> stk;
        vector<int> result;
        TreeNode *cnt = root;
        
        while(!stk.empty() || cnt)
        {
            if(cnt)
            {
                stk.push(cnt);
                result.push_back(cnt->val);
                cnt = cnt->left;
            }else{
                cnt = stk.top();
                stk.pop();
                cnt = cnt->right;
            }
        }
        
        return result;
    }
    
};