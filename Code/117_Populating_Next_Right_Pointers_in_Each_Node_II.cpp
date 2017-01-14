/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/*
modify Tree Level Order: output each level
then connect element in each vector
it's not const space

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
    vector<vector<TreeLinkNode *>> res;
    
    void buildVector(TreeLinkNode * t, int depth)
	{
		if(!t) return;
		if(res.size()==depth) res.push_back({});
		res[depth].push_back(t);
		buildVector(t->left,depth+1);
		buildVector(t->right,depth+1);
    }

    void connect(TreeLinkNode *root) {
        buildVector(root,0);
        for(int line = 0; line < res.size(); ++line)
        {
            TreeLinkNode *cnt = res[line][0];
            for(int i = 1; i < res[line].size();++i) 
            {
                cnt->next = res[line][i];
                cnt = cnt->next;
            }
        }
    }
    

	
};