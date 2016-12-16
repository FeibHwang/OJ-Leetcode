/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

/*
DP question
use another vector to preserve local max sum
transfer function: local_max[i] = max(nums[i],nums[i]+local_max[i-1])
the result is the max of local sum
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> max_part_sum(1,nums[0]);
        
        for(int i = 1; i < nums.size(); ++i)
        {
            int local_max = max(nums[i],nums[i]+max_part_sum[i-1]);
            max_part_sum.push_back(local_max);
        }
        
        int global_sum = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            global_sum = max(global_sum,max_part_sum[i]);
        }
        
        return global_sum;
        
    }
};