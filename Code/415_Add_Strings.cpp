/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

/*
1, add zeros to shorter string 
2, full adder
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num2.length() < num1.length()) return addStrings(num2,num1);
        int diflen = num2.length() - num1.length();
        string zeros = "";
        for(int i = 0; i < diflen; ++i) zeros+='0';
        num1 = zeros + num1;
        
        int c = 0;
        string res(num2);
        for(int j = num1.size()-1; j >= 0; --j)
        {
            res[j] = (num1[j] - '0' + num2[j] - '0' + c) % 10 + '0';
            c = (num1[j] - '0' + num2[j] - '0' + c) / 10;
        }
        return c != 0 ? to_string(c) + res : res;
    }
};