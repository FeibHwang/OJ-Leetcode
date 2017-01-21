/*
Given an array of integers, 
every element appears three times except for one,
which appears exactly once. Find that single one.
*/

/*
using a 32 bit vector to record the number of each bits in each number
mod by 3.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> rec(32,0);
        int res = 0;
        for(int i = 0; i < 32; ++i)
        {
            for(int k = 0; k < nums.size(); ++k)
            {
                rec[i] += (nums[k]>>i)&1;
            }
            res |= rec[i]%3 << i;
        }
        return res;
    }
};