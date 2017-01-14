/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

/*
same as Permutations
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<int> next(nums);
       nextPermutation(next);
       vector<vector<int>> rec = {nums};
       while(next != nums)
       {
           rec.push_back(next);
           nextPermutation(next);
       }
       return rec;
    }
    
    void nextPermutation(vector<int>& nums) {
	if (nums.size()<2) return;
	
	int target = nums.size() - 1;
	
	while (target - 1>-1 && nums[target - 1] >= nums[target]) target--;
	
    if (target == 0) { reverse(nums.begin(), nums.end()); return; }
	target--;
	
	int right = nums.size() - 1;
	
	while (right > target && nums[right] <= nums[target]) right--;
	
	swap(nums[target], nums[right]);
	
	reverse(nums.begin()+target + 1,nums.end());
    }
};