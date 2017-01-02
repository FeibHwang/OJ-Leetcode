/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

/*
very tricky DP solution
http://www.cnblogs.com/grandyang/p/5951422.html

vector rec[i] record whether the array can sum to i
*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1) return false;
        sum /= 2;
        vector<bool> rec(sum+1,false);
        rec[0] = true;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int target = sum; target >= nums[i]; --target)
            {
                rec[target] = rec[target] || rec[target - nums[i]];
            }
        }
        return rec.back();
    }
};