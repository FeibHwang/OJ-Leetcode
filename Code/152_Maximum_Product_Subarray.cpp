/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

/*
DP
using two array to record the max value and the min value
since the smallest value times a nagative value may change to max
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        
        vector<int> max_value(1,nums[0]);
        vector<int> min_value(1,nums[0]);
        
        for(int i = 1; i < nums.size(); ++i)
        {
            int greater_value = max(nums[i] * max_value[i-1], nums[i] * min_value[i-1]);
            int smaller_value = min(nums[i] * max_value[i-1], nums[i] * min_value[i-1]);
            
            max_value.push_back(max(greater_value,nums[i]));
            min_value.push_back(min(smaller_value,nums[i]));
        }
        
        int maxvalue = max_value[0];
        for(int i = 1 ; i < nums.size(); ++i)
        {
            maxvalue = max(maxvalue,max_value[i]);
        }
        return maxvalue;
    }
};