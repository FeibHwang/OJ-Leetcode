/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

/*
first sort array, delete any element that is larger than target
Then just recursively call function
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	 vector<int> pos;
	 for (int i = 0; i < candidates.size(); ++i)
	 {
		 if (candidates[i] <= target)
		 {
			 pos.push_back(candidates[i]);
		 }
	 }
	 if (target == 0) return{ {} };
	 if (pos.empty()) return{};
	 

	 sort(pos.begin(), pos.end());

	 vector<vector<int>> result;
	 for (int i = 0; i < pos.size(); ++i)
	 {
		 vector<int> v2(pos.begin() + i, pos.end());
		 vector<vector<int>> res_tmp = combinationSum(v2, target - pos[i]);
		 //if (res_tmp.empty()) return{};
		 for (int j = 0; j < res_tmp.size(); ++j)
		 {
			 res_tmp[j].push_back(pos[i]);
			 result.push_back(res_tmp[j]);
		 }
	 }
	 return result;
 }
};