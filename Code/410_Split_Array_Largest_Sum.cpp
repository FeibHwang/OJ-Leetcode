/*
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays. 
Note:
If n is the length of array, assume the following constraints are satisfied: 
1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)

Examples: 
Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
*/

/*
very triky binary search solution
so the region of the largest sum is [largest elem, total_sum]
keep binary search this region, see whether the split region will go over m
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        //sort(nums.begin(),nums.end());
        int lower_bound = *max_element(nums.begin(), nums.end());
        int upper_bound = 0;
        for(auto i:nums) upper_bound+=i;
        if(m==1) return upper_bound;
        if(m>=nums.size()) return lower_bound;
        
        while(lower_bound < upper_bound)
        {
            int mid = lower_bound + (upper_bound-lower_bound)/2;
            int group = check(nums,mid);
            if(group <= m) upper_bound = mid;
            else lower_bound = mid+1;
        }
        return lower_bound;
    }
    
    int check(vector<int>& nums, int max_sum)
    {
        int cnt = 0; int res = 0;
        for(int i = 0;i<nums.size();++i)
        {
            if(cnt+nums[i]<=max_sum)
            {
                cnt+=nums[i];
            }else{
                res++;
                cnt=nums[i];
            }
        }
        res++;
        return res;
    }
};