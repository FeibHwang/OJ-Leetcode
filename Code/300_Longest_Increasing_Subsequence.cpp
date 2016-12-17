/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

/*
DP
O(n^2) complesity
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
	int length = nums.size();
	int max_length = 0;

	vector<int> result(length, 1);

	if (nums.empty()) return 0;
	if (nums.size() == 1) return 1;


	for (int i = 1; i < length; ++i)
	{

		for (int j = i - 1; j >= 0; --j)
		{
			if (nums[i]>nums[j])
			{
                result[i] = max(result[i],result[j]+1);
			}
			max_length = max(max_length, result[i]);
		}
	}

	return max_length;
}
};