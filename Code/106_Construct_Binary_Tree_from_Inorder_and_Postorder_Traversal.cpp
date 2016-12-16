/*
Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return nullptr;
        
        int len = inorder.size();
        
        return buildsubTree(inorder,postorder,0,len-1,0,len-1);
    }
    
    TreeNode *buildsubTree(vector<int>& inorder, vector<int>& postorder,int inlft, int inright, int prelft, int preright)
    {
        
        if(inlft > inright) return nullptr;
        
        TreeNode *head = new TreeNode(postorder[preright]);
        if(inlft==inright || prelft==preright) return head;
        
        int i = 0;
        
        for(; i + inlft <= inright; ++i)
        {
            if(inorder[i + inlft]==postorder[preright])
                break;
        }
        int len = inorder.size();
        head->left = buildsubTree(inorder,postorder,inlft,inlft+i-1,prelft,prelft+i-1);
        head->right = buildsubTree(inorder, postorder,inlft+i+1,inright,prelft+i,preright-1);
        
        return head;
    }
};