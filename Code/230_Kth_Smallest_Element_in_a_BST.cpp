/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
*/

/*
always remember the definition of BST
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
	int cntleft = countNodes(root->left);
	if (cntleft == k - 1) return root->val;
	if (cntleft > k - 1) return kthSmallest(root->left, k);
	return kthSmallest(root->right, k - cntleft - 1);
}
    
    int countNodes01(TreeNode* root) {
	if (!root) return 0;

	stack<TreeNode*> sk;
	TreeNode *cnt = root;
	int count = 0;

	while (!sk.empty() || cnt)
	{
		if (cnt)
		{
			sk.push(cnt);
			count++;
			cnt = cnt->left;
		}
		else {
			cnt = sk.top();
			sk.pop();
			cnt = cnt->right;
		}
	}
	return count;
}

    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};