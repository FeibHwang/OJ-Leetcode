/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system 
connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
*/

/*
Classical DP question
*/

class Solution {
public:
    int rob(vector<int>& nums) {
	if (nums.empty()) return 0;
	if (nums.size() == 1) return nums[0];
	vector<int> r(2 * nums.size(), 0);

	r[1] = nums[0];

	for (int i = 2; i <= 2 * nums.size() - 2; i+=2)
	{
		r[i] = r[i - 1];
		if (i == 2)
			r[i + 1] = nums[i - 1];
		else if (i == 4)
			r[i + 1] = nums[i / 2 - 2] + nums[i / 2];
		else
			r[i + 1] = (r[i - 4] + nums[i / 2] > r[i - 3] + nums[i / 2]) ? r[i - 4] + nums[i / 2] : r[i - 3] + nums[i / 2];
	}

	return (r[r.size() - 2] > r[r.size() - 1]) ? r[r.size() - 2] : r[r.size() - 1];
}
};