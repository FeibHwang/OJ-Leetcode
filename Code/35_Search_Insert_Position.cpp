/***************************************************************************
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
**************************************************************************/

/***************************************************************************
 * a very naive approach, use direct search, binary search can improve effeciency
 * **************************************************************************/

class Solution {
    
public:

    int searchInsert(vector<int>& nums, int target)
    {
	    if (nums.empty()) { return 0; }
	    if (target <= nums[0]) { return 0; }
	    if (target > nums[nums.size() - 1]) { return nums.size(); }

	    for (int i = 0; i<nums.size(); ++i)
	    {
		    if (target <= nums[i + 1] && i < nums.size()-1) { return ++i; }
	    }
	    return NULL;
    }
    
    
};