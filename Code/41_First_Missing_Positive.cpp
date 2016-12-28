/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

/*
basic thought: put positive number into its position
some potential harmful case: element larger than array size, element smaller than 0, duplicate element
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size();++i)
        {
            while(nums[i] != i+1){
                if(nums[i]>=nums.size() || nums[i] <= 0 || nums[i] == nums[nums[i]-1]) break;
                int temp = nums[i];
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i+1) return i+1;
        }
        return nums.size()+1;
    }
};