/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

/*
record elem smaller than target, sort
for each elem, find combinationSum2(v2, target - elem)
v2 is array after alem
*/


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
	 

	 sort(pos.rbegin(), pos.rend());

	 vector<vector<int>> result;
	 for (int i = 0; i < pos.size(); ++i)
	 {
	     if(i>0 && pos[i]==pos[i-1]) continue;
		 vector<int> v2(pos.begin() + i + 1, pos.end());
		 vector<vector<int>> res_tmp = combinationSum2(v2, target - pos[i]);
		 for (int j = 0; j < res_tmp.size(); ++j)
		 {
			 res_tmp[j].push_back(pos[i]);
			 result.push_back(res_tmp[j]);
		 }
	 }
	 return result;
    }
};



/*
dfs solution:
compare with Combination Sum solution
need some techniques to avoid duplicates
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	 sort(candidates.begin(),candidates.end());
	 dfs(candidates,target,0);
	 return res;
}

    vector<vector<int>> res;
    vector<int> hold;
    
    
    void dfs(vector<int>& candidates, int target, int start)
    {
        if(target == 0)
        {
            res.push_back(hold);
            return;
        }
        
        int previous = -1;
        for(int i = start; i<candidates.size(); ++i)
        {
            if(previous == candidates[i]) continue;
            if(target < candidates[i]) return;
            previous = candidates[i];
            // avoid using same value from last loop
            hold.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i+1);
            hold.pop_back();
        }
    }
};