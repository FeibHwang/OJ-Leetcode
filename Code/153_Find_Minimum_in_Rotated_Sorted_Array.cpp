/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

/*
linear search, I will write a binary search later days
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = nums.size();
        for(int k=0; k < i-1; ++k)
        {
            if(nums[k]>nums[k+1])
                return nums[k+1];
        }
        return nums[0];
    }
};