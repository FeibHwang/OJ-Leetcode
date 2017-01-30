/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/

/*
Binary search:
choose middle point, there is at least one array is single increasing
binary search that one if range fit, otherwise searchfor the other array
*/



class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return serachfor(nums,target,0,nums.size()-1);
    }
    
    bool serachfor(vector<int>& nums, int target, int start, int end)
    {
        int i = start;
        int j = end;
        while(i <= j)
        {
            int mid = (i+j) / 2;
            if(nums[mid]==target || nums[i]==target || nums[j]==target) return true;
            if(nums[i] <= nums[mid] && target < nums[mid] && target > nums[i]) 
            {
                    return binary_search(nums,target,i+1,mid-1);
            }
            if(nums[mid] <= nums[j] && target < nums[j] && target > nums[mid]) 
            {
                    return binary_search(nums,target,mid+1,j-1);
            }
            return serachfor(nums,target,i+1,mid-1) || serachfor(nums,target,mid+1,j-1);
        }
        return false;
    }
    
    bool binary_search(vector<int>& nums, int target, int start, int end)
    {
        int i = start;
    	int j = end;
    	while (i <= j)
    	{
    		int mid = (i + j) / 2;
    		if (nums[mid] == target) return true;
    		else if (nums[mid] < target) i = mid+1;
    		else j = mid-1;
    	}
        return false;
    }
};