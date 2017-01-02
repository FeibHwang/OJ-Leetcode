/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

/*
very elegent algorithm from top solution
the key thing is to record which element has been choosen, using a new function with recurent and a counter will do
*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rec;
        
        permuterec(nums,0,rec);
        return rec;
    }
    
    void permuterec(vector<int>& nums, int begin, vector<vector<int>> &rec)
    {
        if(begin >= nums.size())
        {
            rec.push_back(nums);
            return;
        }
        
        for(int i = begin; i < nums.size(); ++i)
        {
            swap(nums[i],nums[begin]);
            permuterec(nums, begin+1, rec);
            swap(nums[i],nums[begin]);
        }
    }
};