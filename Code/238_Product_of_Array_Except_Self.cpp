/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

/*
here I use dicision
think about another algorithm later
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        vector<int> zero = {};
        if(nums.empty() || nums.size()==1){return nums;}
        for(int i = 0; i< nums.size(); ++i)
        {
            if(nums[i]==0){zero.push_back(i);}
        }
        if(zero.empty()){
            int rest_mul = 1;
            for (int j = 1; j< nums.size(); ++j)
            {
                rest_mul *= nums[j];
            }
            result[0] = rest_mul;
            for(int j = 1; j< nums.size(); ++j)
            {
                result[j] = result[0] / nums[j] * nums[0];
            }
        }
        else if(zero.size() > 1) {return result;}
        else{
            int rest_mul = 1;
            for (int j = 0; j< nums.size(); ++j)
            {
                if(j != zero[0]){
                rest_mul *= nums[j];
                }
            }
            result[zero[0]] = rest_mul;
        }
        return result;
    }
};