/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, 
and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.
*/

/*
compare left most node depth with right most
if equal, then it's complete, node = 2^(depth-1)
not equal, recurrsively call the function until banlanced 
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
    int countNodes01(TreeNode* root) {
        if(!(root)) return 0;
        stack<TreeNode *> stk;
        TreeNode *cnt = root;
        int count = 0;
        
        while(!stk.empty() || cnt)
        {
            if(cnt)
            {
                stk.push(cnt);
                count++;
                cnt = cnt->left;
            }else{
                cnt = stk.top();
                stk.pop();
                cnt = cnt->right;
            }
        }
        return count;
    }
    
    int getDepthleft(TreeNode* root)
    {
        int cnt = 0;
        TreeNode *count = root;
        while(count)
        {
            cnt++;
            count = count -> left;
        }
        return cnt;
    }
    
    int getDepthright(TreeNode* root)
    {
        int cnt = 0;
        TreeNode *count = root;
        while(count)
        {
            cnt++;
            count = count -> right;
        }
        return cnt;
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int left = getDepthleft(root);
        int right = getDepthright(root);
        
        if(left==right)
        {
            return (1 << left)-1;
        }
        
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};