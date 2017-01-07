/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

//Same as 3 sum, settle 2 point first, then perform 2 sum for the rest

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        if(nums.size() < 4) return {};
        for(int i = 0; i < nums.size()-3; ++i)
        {
            if(i > 0 && nums[i-1]==nums[i]) continue;
            for(int j = i+1; j < nums.size()-2; ++j)
            {
                int vtarget = target - nums[i] - nums[j];
                if(j > i+1 && nums[j-1]==nums[j]) continue;
                find2Sum (nums,i,j,vtarget);
            }
        }
        return rec;
    }
    
    vector<vector<int>> rec;
    
    void find2Sum (vector<int>& nums, int fstl, int sndl, int target)
    {
        int l = sndl + 1, r = nums.size()-1;
        while(l < r)
        {
            if(nums[l] + nums[r] == target) 
            {
                vector<int> tmp = {nums[fstl],nums[sndl],nums[l],nums[r]};
                rec.push_back(tmp);
                while(l+1 < r && nums[l] == nums[l+1]) l++;
                while(r-1 > l && nums[r-1] == nums[r]) r--;
                l++;r--;
            }else{
                nums[l] + nums[r] > target ? r--:l++;
            }
        }
    }
};