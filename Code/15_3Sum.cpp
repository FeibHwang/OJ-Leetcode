/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/*
Sort vector
Settle the left element, perform two sum on the right side array
For both the left element and the two sum operation, jump the duplicate, since the array is sorted, just compare with previous element
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};
        vector<int> cnum(nums);
        sort(cnum.begin(),cnum.end());
        
        vector<vector<int>> res;
        for(int i = 0; i < cnum.size()-2; ++i)
        {
            vector<int> rest;
            rest = twoSum(cnum,0-cnum[i],i+1,cnum.size()-1);
            if(!rest.empty() && i>0 && cnum[i]!=cnum[i-1])
            {
                rest.push_back(i);
                vector<int> ress= {-1,-1,-1};
                for(int k = 0; k < nums.size(); ++k)
                {
                    if(nums[k] == cnum[rest[0]] && res[0] == -1) ress[0]=k;
                    else if(nums[k]==cnum[rest[1]] && res[1]==-1)ress[1]=k;
                    else if(nums[k]==cnum[rest[2]] && res[2]==-1)ress[2]=k;
                }
                res.push_back(ress);
            }
            
        }
        return res;
    }
    
    vector<int> twoSum(vector<int>& nums, int target, int left, int right) {
        int i = left; int j = right; //left/right pointer
        while(i<j)
        {
            int sum = nums[i]+nums[j];
            if(sum == target) break;
            if(sum < target) i++;
            if(sum > target) j--;
        }
        if(nums[i]+nums[j]==target)return {i,j};
        return {};
    }
};