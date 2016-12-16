/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
do it recurrently, easy to think 
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
    TreeNode* sortedArrayToBST01(vector<int>& nums) {
	
	if (nums.empty()) return nullptr;

	TreeNode *head = new TreeNode(nums[0]);

	if (nums.size() == 1) return head;

	int k = nums.size() / 2;

	head->val = nums[k];

	vector<int> left;
	vector<int> right;

	left.assign(nums.begin(), nums.begin() + k);
	right.assign(nums.begin() + k + 1, nums.end());

	head->right = sortedArrayToBST(right);
	head->left = sortedArrayToBST(left);
	return head;

    }
    
    TreeNode * generateTree(int left, int right, vector<int>& nums)
    {
        if(left > right) return nullptr;
        
        else if(left == right) return new TreeNode(nums[left]);
        
        else
        {
            int mid = (left + right) / 2;
            TreeNode *head = new TreeNode(nums[mid]);
            head->left = generateTree(left, mid-1, nums);
            head->right = generateTree(mid+1, right,nums);
            return head;
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    
        return generateTree(0,nums.size()-1,nums);
    }
};