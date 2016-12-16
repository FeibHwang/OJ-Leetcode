/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

/*
I use another vector to record individual element of the original vector
then apply to the same method
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        vector<int> arr = {nums[0]};
        for(int i=0; i < nums.size(); ++i)
        {
            if(nums[i]!=arr[arr.size()-1])
                arr.push_back(nums[i]);
        }
        return findMin_I(arr);
    }
    
    int findMin_I(vector<int>& nums) {
        int i = nums.size();
        for(int k=0; k < i-1; ++k)
        {
            if(nums[k]>nums[k+1])
                return nums[k+1];
        }
        return nums[0];
    }
};