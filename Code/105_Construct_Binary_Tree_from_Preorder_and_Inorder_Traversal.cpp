/*
Given preorder and inorder traversal of a tree, construct the binary tree.
*/

/*
recurrent algorithm
find root, perform same task on left and right
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.empty()) return nullptr;
        int len = inorder.size();
        
        return buildsubTree(inorder,preorder,0,len-1,0,len-1);
        
    }
    
    TreeNode *buildsubTree(vector<int>& inorder, vector<int>& preorder,int inlft, int inright, int prelft, int preright)
    {
        
        if(inlft > inright) return nullptr;             //pay attention to the corner ocassion
        
        TreeNode *head = new TreeNode(preorder[prelft]);
        if(inlft==inright || prelft==preright) return head;
        
        int i = 0;
        
        for(; i + inlft <= inright; ++i)
        {
            if(inorder[i + inlft]==preorder[prelft])
                break;
        }
        int len = inorder.size();
        head->left = buildsubTree(inorder,preorder,inlft,inlft+i-1,prelft+1,prelft+i);
        head->right = buildsubTree(inorder, preorder,inlft+i+1,inright,prelft+i+1,preright);
        
        return head;
    }
};