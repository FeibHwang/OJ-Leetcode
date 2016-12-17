/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

/*
not very clever way, is there a better solution?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size_whole = nums.size();
        vector<int> begin = {};
        for(int i = 0; i <= size_whole; ++i)
        {
            begin.push_back(i);
        }
        
        for(int j = 0; j < size_whole; ++j)
        {
            begin[nums[j]] = size_whole + 1;
        }
        
        for(int k = 0; k <= size_whole; ++k)
        {
            if(begin[k] != size_whole + 1)
            {
                return begin[k];
            }
        }
        return NULL;
        
    }
};