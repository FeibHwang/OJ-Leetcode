//***********************************************************************
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.

//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

//You are given a target value to search. If found in the array return its index, otherwise return -1.

//You may assume no duplicate exists in the array.
//***********************************************************************
//***********************************************************************
//Similar to the binary search, but require extra step to slove the rotation problem
//***********************************************************************

class Solution {
public:
    int search(vector<int>& nums, int target) {
	if (nums.empty()) return -1;
	if (nums.size() == 1) { if (nums[0] == target) { return 0; } else { return -1; } }
	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target) { return mid; }
		if (nums[left]<nums[mid] && nums[mid] < nums[right] && mid != left)
		{
			vector<int> tmp;
			tmp.assign(nums.begin() + left, nums.begin() + right + 1);
			return (find_target(tmp, target) != -1) ? left + find_target(tmp, target) : find_target(tmp, target);
		}
		if (nums[left] < nums[mid] && target < nums[mid] && target >= nums[0])
		{
			vector<int> tmp;
			tmp.assign(nums.begin() + left, nums.begin() + mid + 1);
			return (find_target(tmp, target) != -1) ? left + find_target(tmp, target) : find_target(tmp, target);
		}
		if (nums[left] < nums[mid] && (target > nums[mid] || target < nums[left]))
		{
			left = mid + 1;
		}
		if (nums[mid] < nums[right] && target <= nums[right] && target > nums[mid])
		{
			vector<int> tmp;
			tmp.assign(nums.begin() + mid, nums.begin() + right+1);
			return (find_target(tmp, target) != -1) ? mid + find_target(tmp, target) : find_target(tmp, target);
		}
		if (nums[mid] < nums[right] && (target > nums[right] || target < nums[mid]))
		{
			right = mid - 1;
		}
		if (mid == left)
		{
			if (nums[right] == target) { return right; }
			else { return -1; }
		}
	}
	return -1;
}
    
    int find_target(vector<int>& nums, int target)  //traditional algorithm to find a target
    {
    	int left, right;
    	int mid;
	    left = 0;
	    right = nums.size() - 1;
	    while (left <= right)
	    {
		    mid = (left + right) / 2;
		    if (target == nums[mid]) return mid;
		    else if (target < nums[mid]) right = mid - 1;
		    else if (target > nums[mid]) left = mid + 1;
	    }
	    return -1;
    }
