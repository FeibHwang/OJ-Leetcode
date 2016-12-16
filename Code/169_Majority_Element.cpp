/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

/*
Very clever algorithm
using the fact that one of the element appears more than ⌊ n/2 ⌋ times
so let different element cancel with each other, only the result will remain
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int coor = 0, comp = 1;
        for(int i = 0; i < nums.size(); ++i){
            nums[i]==nums[coor]? comp++:comp--;
            if(!comp){
                coor = i;
                comp = 1;
            }
        }
        
        return nums[coor];
    }
};