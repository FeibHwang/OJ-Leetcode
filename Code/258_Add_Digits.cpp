/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

A naive implementation of the above process is trivial. Could you come up with other methods?
What are all the possible results?
How do they occur, periodically or randomly?
You may find this Wikipedia article useful.
*/

/*
I don't know the mathmatical svhematic behind it
*/

class Solution {
public:
    int addDigits01(int num) {
        if(num==9) return 9;
        else if(num > 0 && num % 9==0) return 9;
        else return num % 9;
    }
    
    int addDigits(int num) {
        return 1 + (num-1)%9;
    }
};