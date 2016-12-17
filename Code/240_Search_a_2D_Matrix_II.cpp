/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

/*
first locate possible line
then binary search
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int start;
        bool fd = false;
        
        for(int i = 0;  i<matrix.size(); ++i)
        {
            if(matrix[i][matrix[0].size()-1]>=target)
            {
                if(matrix[i][matrix[0].size()-1]==target) return true;
                start = i;
                break;
            }
        }
        
        for(; start < matrix.size();++start)
        {
            fd = fd || find_target(matrix[start],target);
            if(fd) return fd;
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