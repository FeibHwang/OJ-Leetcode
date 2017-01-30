/*
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
*/

/*
not very efficient dfs
use a set to record duplicates
*/


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size()<2) return res; 
        for(int i = 0; i < nums.size()-1; ++i)
        {
            dfs(nums,i);
        }
        
        for(auto c : mp)
        {
            res.push_back(c);
        }
        return res;
    }
    
    vector<vector<int>> res = {};
    vector<int> path = {};
    set<vector<int>> mp;
    
    void dfs(vector<int>& nums, int i)
    {
        if(i==nums.size())
        {
            return;
        }
        
        if(path.size()>0)
        {
            if(nums[i]>=path.back())
            {
                path.push_back(nums[i]);
                if(mp.find(path) == mp.end()) 
                {
                    mp.insert(path);
                }
                dfs(nums,i+1);
                path.pop_back();
            }
            dfs(nums,i+1);
        }else{
            path.push_back(nums[i]);
            dfs(nums,i+1);
            path.pop_back();
        }
    }
};