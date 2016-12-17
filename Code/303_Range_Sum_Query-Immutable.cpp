/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

/*
just accumulate the sum
recorded
*/

class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sum=0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            part_sum.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return (i==0)?part_sum[j]:part_sum[j]-part_sum[i-1];
    }
    
    vector<int> part_sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);