/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
*/

/*
inorder traversal: push treenode into vector
return it's next
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        target = p;
        vector<TreeNode *> rec = Tree_LDR(root);
        return index < rec.size()-1 ? rec[index+1]:nullptr;
    }
    
    int index;
    TreeNode* target;
    
    	vector<TreeNode *> Tree_LDR(TreeNode *root)
    	 {
    		 vector<TreeNode *> res;
    		 if (!root) return res;
    		 stack<TreeNode*> stk;
    		 TreeNode *current = root;
    		 while (current || !stk.empty())
    		 {
    			 if (current)
    			 {
    				 stk.push(current);
    				 current = current->left;
    			 }
    			 else {
    				 current = stk.top();
    				 if(current==target) index = res.size();
    				 res.push_back(current);
    				 current = current->right;
    				 stk.pop();
    			 }
    		 }
    		 return res;
     }
};