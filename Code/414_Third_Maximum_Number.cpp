/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

/*
maintain 3 number represent the top 3 largetst number, compare with all the number in vector
avoid same number
pay attention to coundary case, use long not int 
*/


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = long(INT_MIN)-1; long second = first; long third = first;
        for(int i = 0; i < nums.size(); ++i)
        {
            int comp = long(nums[i]);
            if(comp==first || comp==second || comp==third) continue;
            if(comp>first)
            {
                third = second;
                second = first;
                first = comp;
                continue;
            }
            if(comp>second)
            {
                third = second;
                second = comp;
                continue;
            }
            if(comp>third)
            {
                third =  comp;
                continue;
            }
        }
        return third == long(INT_MIN)-1 ? first:third;
    }
};