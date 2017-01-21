/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

/*
similiar to single number I
after xor, the result = 2 single number xor
but the '1' bit in result shows two number is different in this bit
so construct using the different bit:
i.e:
1101
1010
xor:0111

construct: rec = 0001 <-- choose the last bit

1101 ^ 0001 = 1
1010 ^ 0001 = 0

we can classify the nums into 2 group:
nums[i] ^ 0001 != 0
nums[i] ^ 0001 == 0

the duplicate number will be classify into one of the 2 group together
the two single number will be classified into seperate group

a tricky way to construct rec: rec = rec & (~(rec-1))

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int rec = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            rec ^= nums[i];
        }
        
        rec = rec & (~(rec-1));
        
        vector<int> res(2,0);
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if((rec & nums[i]) != 0)
            {
                res[0] ^= nums[i];
            }else{
                res[1] ^= nums[i];
            }
        }
        return res;
    }
};