/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?
*/

/*
there is a better solution
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return 1;
        
        vector<int> rec(nums.size(),1);
        int i = 1;
        for(; i < nums.size(); ++i)
        {
            if(nums[i]!=nums[i-1])
                break;
            if(i == nums.size()-1) return 1;
        }
        
        rec[i] = 2;
        int up_down;
        if(nums[i-1]>nums[i]) up_down = 1;
        else up_down = -1;
        
        for(i = i + 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i-1])
            {
                if(up_down == 1) 
                {
                    rec[i] = rec[i-1]+1;
                    up_down = -1;
                }
                else
                {
                    rec[i] = rec[i-1];
                }
            }
            
            else if(nums[i]==nums[i-1])
            {
                rec[i]=rec[i-1];
            }
            
            else
            {
                if(up_down == 1)
                {
                    rec[i]=rec[i-1];
                }
                else
                {
                    rec[i] = rec[i-1]+1;
                    up_down = 1;
                }
            }
        }
        
        return *(rec.end()-1);
    }
};