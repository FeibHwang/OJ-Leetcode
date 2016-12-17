/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
*/

/*
Classic DP question
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),0), parent(nums.size(),0), res;
        int mx = 0, mx_idx = 0;
        
        for(int i = nums.size()-1; i >= 0; --i)
        {
            for(int j = i; j < nums.size(); ++j)
            {
                if(nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if(mx < dp[i])
                    {
                        mx = dp[i];
                        mx_idx = i;
                    }
                }
            }
        }
        
        for(int i = 0; i < mx; ++i)
        {
            res.push_back(nums[mx_idx]);
            mx_idx = parent[mx_idx];
        }
        return res;
    }
    
    //http://www.cnblogs.com/grandyang/p/5625209.html
    vector<int> largestDivisibleSubset01(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0), parent(nums.size(), 0), res;
        int mx = 0, mx_idx = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (mx < dp[i]) {
                        mx = dp[i];
                        mx_idx = i;
                    }
                }
            }
        }
        for (int i = 0; i < mx; ++i) {
            res.push_back(nums[mx_idx]);
            mx_idx = parent[mx_idx];
        }
        return res;
    }
};