/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/


/*
similar to find all numbers disappeared in an array, 
sweep the number in the array, use it as the index of the array
the index number is set to negative of the origonal,
but if the index number is negative already, means that the number has apperaed twice
then we can push the number to result.
*/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[abs(nums[i])-1]<0){
                res.push_back(abs(nums[i]));
                continue;
            }
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
        return res;
    }
};