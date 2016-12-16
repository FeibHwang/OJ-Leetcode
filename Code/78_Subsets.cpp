/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*
recursion methord
find subsets of nums[0..n-1]
then add them with the final number
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> start = {};
        result.push_back(start);
        
        if(nums.empty())  return result;
        
        vector<int> body(nums.begin(),nums.end()-1);
        result = subsets(body);
        
        int tail = *(nums.end()-1);
        int length = result.size();
        for(int i = 0; i < length; ++i)
        {
            vector<int> tmp = result[i];
            tmp.push_back(tail);
            result.push_back(tmp);
        }
        
        return result;
    }
};