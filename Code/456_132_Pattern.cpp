/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]

Output: False

Explanation: There is no 132 pattern in the sequence.
Example 2:
Input: [3, 1, 4, 2]

Output: True

Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:
Input: [-1, 3, 2, 0]

Output: True

Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
*/

/*
maintain a stack
an int val third to preserve the "2" of the "132"
so we want "2" to be as close as to "3" to increase finding chance
so we will maintain the position of "32", once we find "1", we can return true then
*/


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int third = INT_MIN;
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i]<third) return true;
            else{
                while(!stk.empty() && nums[i]>stk.top())
                {
                    third = stk.top();
                    stk.pop();
                }
                stk.push(nums[i]);
            }
        }
        return false;
        
    }
};