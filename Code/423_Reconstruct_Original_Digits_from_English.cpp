/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
*/

/*
look for dinstinct char in each word
*/

class Solution {
public:
    string originalDigits(string s) {
        vector<int> ch(10,0); //zwuxvgfohi
        for(int i = 0; i < s.size(); ++i)
        {
        	if(s[i]=='z') ch[0]++;
        	else if(s[i]=='w') ch[1]++;
        	else if(s[i]=='u') ch[2]++;
        	else if(s[i]=='x') ch[3]++;
        	else if(s[i]=='s') ch[4]++;
        	else if(s[i]=='g') ch[5]++;
        	else if(s[i]=='f') ch[6]++;
        	else if(s[i]=='o') ch[7]++;
        	else if(s[i]=='h') ch[8]++;
        	else if(s[i]=='i') ch[9]++;
        }
        vector<int> num(10,0);
        num[0]=ch[0];
        num[2]=ch[1];
        num[4]=ch[2];
        num[6]=ch[3];
        num[7]=ch[4]-num[6];
        num[8]=ch[5];
        num[5]=ch[6]-num[4];
        num[1]=ch[7]-num[0]-num[2]-num[4];
        num[3]=ch[8]-num[8];
        num[9]=ch[9]-num[6]-num[5]-num[8];
        
        string res;
       for(int i = 0; i < num.size(); ++i)
        {
            char val = i+'0';
        	for(int j = 0; j < num[i]; j++)
        	{
        		res += val;
        	}
        }
        
        return res;
    }
};