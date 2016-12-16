/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

/*
initializing: pre-order traversal put the val into a stack
hasNext: stack not empty
next: stack pop
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if(root)
        {
            TreeNode* count = root;
            stack<TreeNode*> stk;
            while(count || !stk.empty())
            {
                if(count)
                {
                    stk.push(count);
                    count = count->right; 
                }else{
                    count = stk.top();
                    stk.pop();
                    stack_tree.push(count);
                    count = count->left;
                }
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stack_tree.size() > 0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = stack_tree.top();
        stack_tree.pop();
        return tmp->val;
    }

private:
    stack<TreeNode*> stack_tree;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */