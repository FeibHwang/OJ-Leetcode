/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

/*
record position of 0
erase, add 0
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       
       vector<int> zero_count = {};
       for(int i = 0; i < nums.size(); ++i)
       {
           if(nums[i] == 0)
           {
               zero_count.push_back(i);
           }
       }
       if(! zero_count.empty())
       {
           for(int k = 0; k < zero_count.size(); ++k)
           {
               nums.erase(nums.begin()+zero_count[k]-k);
               nums.push_back(0);
           }
       }
        
    }
};


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i]==0)
            {
                cnt++;
            }else{
                swap(nums[i-cnt],nums[i]);
            }
        }
    }
};