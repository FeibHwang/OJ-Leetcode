/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II
*/

/*
space O(n), I will write another later
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
	    int rotate = k % n;
    	vector<int> tail = {};
    	vector<int> head = {};
    	tail.assign(nums.begin(), nums.end() - rotate);
    	head.assign(nums.end() - rotate, nums.end());
    	head.insert(head.end(), tail.begin(), tail.end());
    	nums = head;
    }
};