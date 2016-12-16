/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/*
2 recurrersive path:
connect inside of one tree
connect between 2 trees

*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root && (root->right) && (root->left))
        {
              connect_inside(root);
              connect_outside(root->left, root->right);
        }
    }
    
    void connect_outside(TreeLinkNode *body1, TreeLinkNode *body2)
    {
        if((body1->left) || (body2->right))
        {
            body1->right->next = body2->left;
            connect_outside(body1->left, body1->right);
            connect_outside(body2->left, body2->right);
            connect_outside(body1->right, body2->left);
            
        }
    }
    
    void connect_inside(TreeLinkNode *body)
    {
        if(body && body->left && body->right)
        {
            body->left->next = body->right;
            connect_inside(body->left);
            connect_inside(body->right);
        }
    }
};