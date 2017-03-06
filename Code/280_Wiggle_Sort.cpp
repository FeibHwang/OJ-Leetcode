/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
*/

/*
O(n): one pass
for each i,i+1: even i: small->large, odd i: large->small
sort 2 element: use swap
*/

class Solution {
public:
    void wiggleSort(vector<int>& s) {
        bool sw = true;
        if(s.size()<2) return;
        for(int i = 0; i < s.size()-1; ++i)
        {
            if((!sw&&s[i]<s[i+1]) || (sw&&s[i]>s[i+1])) swap(s[i],s[i+1]);
            sw = !sw;
        }
    }
};