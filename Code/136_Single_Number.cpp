/*
Given an array of integers, every element appears twice except for one. Find that single one.
*/

/*
very interesting algorithm
mathmetical fact:

0 xor any = any
A xor A = 0
A xor B xor A = A xor A xor B = 0 xor B = B

*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            result = result^nums[i];
        }
        return result;
    }
};