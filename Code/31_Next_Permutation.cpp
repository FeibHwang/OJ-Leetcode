/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/*
Find the largest index k such that nums[k] < nums[k + 1]
if no such k, reverse whole vector
Find the largest index l greater than k such that nums[k] < nums[l].
Swap the value of nums[k] with that of nums[l]
Reverse the sequence from nums[k + 1] up to and including the final element nums[nums.size() - 1]
*/

class Solution {
public:
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