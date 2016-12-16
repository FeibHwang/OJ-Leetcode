/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

/*
bubble sort 2 trial, inefficient
or just sort and choose
*/

class Solution {
public:
    int findKthLargest01(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        for(int i = 0; i < k; ++i)
        {
            for(int j = 1; j < nums.size()-i; ++j)
            {
                if(nums[j-1]>nums[j])
                {
                    int tmp = nums[j];
                    nums[j] = nums[j-1];
                    nums[j-1] = tmp;
                }
            }
        }
        return nums[nums.size()-k];
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};