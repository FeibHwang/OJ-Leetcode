/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

/*
2 vector:
left_min: the min elem on left of nums
right_max: the max elem on right of nums
then just decide
*/


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;
        vector<int> left_min(nums.size(),INT_MIN);
        vector<int> right_max(nums.size(),INT_MIN);
        
        left_min[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            left_min[i] = min(left_min[i-1],nums[i]);
        }
        
        right_max[nums.size()-1] = nums.back();
        for(int j = nums.size()-2; j >= 0; --j)
        {
            right_max[j] = max(right_max[j+1],nums[j]);
        }
        
        for(int k = 1; k < nums.size()-1; ++k)
        {
            if(left_min[k-1] < nums[k] && nums[k] < right_max[k+1]) return true;
        }
        return false;
    }
    
    
    bool increasingTriplet01(vector<int>& nums) {
    int c1 = INT_MAX, c2 = INT_MAX;
    for (int x : nums) {
        if (x <= c1) {
            c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
        } else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
            c2 = x;           // x is better than the current c2, store it
        } else {              // here when we have/had c1 < c2 already and x > c2
            return true;      // the increasing subsequence of 3 elements exists
        }
    }
    return false;
}
};