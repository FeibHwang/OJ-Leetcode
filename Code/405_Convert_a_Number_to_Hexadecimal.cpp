/*
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used. 
Note: 
All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.

Example 1: 
Input:
26

Output:
"1a"

Example 2: 
Input:
-1

Output:
"ffffffff"
*/

/*
I use a hash map to record binary-hex conversion
there is got to be a better way!!
*/


class Solution {
public:
    string toHex(int num) {
        string rec = "00000000000000000000000000000000";
        for(int i = 0; i < 32; ++i)
        {
            rec[31-i] = (num>>i) & 1 == 1 ? '1':'0';
        }
        
        unordered_map<string,char> dict;
        dict["0000"] = '0';
        dict["0001"] = '1';
        dict["0010"] = '2';
        dict["0011"] = '3';
        dict["0100"] = '4';
        dict["0101"] = '5';
        dict["0110"] = '6';
        dict["0111"] = '7';
        dict["1000"] = '8';
        dict["1001"] = '9';
        dict["1010"] = 'a';
        dict["1011"] = 'b';
        dict["1100"] = 'c';
        dict["1101"] = 'd';
        dict["1110"] = 'e';
        dict["1111"] = 'f';
        
        string res = "";
        bool start = false;
        for(int i = 0; i <= 28; i+=4)
        {
            if(dict[rec.substr(i,4)]!='0') start = true;
            if(start) res.push_back(dict[rec.substr(i,4)]);
        }
        return res.empty()?"0":res;
        
    }
};