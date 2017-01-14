/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

/*
simply keep expanding the maxmum distance you can reach
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        for(int range = 0; i < nums.size() && i <= range; ++i)
        {
            range = max(i+nums[i],range);
        }
        return i == nums.size();
    }
};