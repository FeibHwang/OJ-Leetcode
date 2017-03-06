/*
After robbing those houses on that street, 
the thief has found himself a new place for his thievery so that he will not get too much attention. 
This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
*/

/*
DP from top solution
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
	    if (nums.size() == 1) return nums[0];
	    vector<int> left(nums.begin(),nums.end()-1);
	    vector<int> right(nums.begin()+1,nums.end());
	    return max(robI(left),robI(right));
    }
    
    int robI(vector<int>& nums) {
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