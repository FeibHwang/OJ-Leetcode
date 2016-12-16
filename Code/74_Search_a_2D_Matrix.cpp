/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

//two step: binary search to locate possible line, binary search the target

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0;
        int down = matrix.size()-1;
        int mid;
        while(up <= down)
        {
            mid = (up + down) / 2;
            if(matrix[mid][0]<=target && matrix[mid][matrix[mid].size()-1]>=target) return find_target(matrix[mid],target);
            else if(target < matrix[mid][0]) down = mid - 1;
            else if(target > matrix[mid][matrix[mid].size()-1]) up = mid + 1;
        }
        return false;
        
    }
    
    bool find_target(vector<int>& nums, int target)
    {
    	int left, right;
    	int mid;
	    left = 0;
	    right = nums.size() - 1;
	    while (left <= right)
	    {
		    mid = (left + right) / 2;
		    if (target == nums[mid]) return true;
		    else if (target < nums[mid]) right = mid - 1;
		    else if (target > nums[mid]) left = mid + 1;
	    }
	    return false;
    }
};