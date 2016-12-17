/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

/*
recurrsive algorithm is most straight forward
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> leftstr;
        vector<string> rightstr;
        
        if((root))
        {
            if((root->left))
            {
                leftstr = binaryTreePaths(root -> left);
                for(int i = 0; i < leftstr.size(); ++i)
                {
                    leftstr[i] = to_string(root->val) + "->" + leftstr[i];
                }
            }
            if((root->right))
            {
                rightstr = binaryTreePaths(root -> right);
                for(int i = 0; i < rightstr.size(); ++i)
                {
                    rightstr[i] = to_string(root->val) + "->" + rightstr[i];
                }
            }
            if(!(root->left) && !(root->right))
            {
                leftstr.push_back(to_string(root->val));
            }
        }
        else
        {
            return {};
        }
        
        leftstr.insert(leftstr.end(),rightstr.begin(),rightstr.end());
        return leftstr;
    }
};