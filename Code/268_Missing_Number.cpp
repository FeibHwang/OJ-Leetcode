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
    int missingNumber01(vector<int>& nums) {
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


/*
of course there is!!!
cnt = 0
first from 0~n let cnt xor with each number
then let cnt xor with nums[i]
the existing number is xor twice, so eleminated!!!!
*/

    int missingNumber(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i <= nums.size(); ++i) cnt ^= i;
        for(int i = 0; i < nums.size(); ++i) cnt ^= nums[i];
        return cnt;
    }

/*
another one, save one more fore loop!!!
*/
    int missingNumber(vector<int>& nums) {
    long n = nums.size();
    return n * (n+1) / 2 - accumulate(begin(nums), end(nums), 0);
}
};