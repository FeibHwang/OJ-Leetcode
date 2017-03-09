/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible. 
Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.

Example 1: 
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2: 
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3: 
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

/*
write function of remove one digits
execute k times
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = num;
        for(int i = 1; i <= k && res!=""; i++ )
        {
            res = remove_one_dig(res);
        }
        while(res!=""&&res[0]=='0') res = res.substr(1);
        return res == "" ? "0":res;
    }
    
    string remove_one_dig(string num)
    {
        for(int i = 0; i < num.size()-1; ++i)
        {
            if(num[i]>num[i+1])
            {
                return num.substr(0,i)+num.substr(i+1);
            }
        }
        return num.substr(0,num.length()-1);
    }
};