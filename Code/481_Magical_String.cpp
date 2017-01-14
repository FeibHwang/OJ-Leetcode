/*
A magical string S consists of only '1' and '2' and obeys the following rules:

The string S is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string S itself.

The first few elements of string S is the following: S = "1221121221221121122……"

If we group the consecutive '1's and '2's in S, it will be:

1 22 11 2 1 22 1 22 11 2 11 22 ......

and the occurrences of '1's or '2's in each group are:

1 2	2 1 1 2 1 2 2 1 2 2 ......

You can see that the occurrence sequence above is the S itself.

Given an integer N as input, return the number of '1's in the first N number in the magical string S.

Note: N will not exceed 100,000.

Example 1:
Input: 6
Output: 3
Explanation: The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.
*/



/*
very nesty but beats 90% submission
implment directly according to the definition
*/

class Solution {
public:
    int magicalString(int n) {
        if(n<=3) return (n!=0)*1;
        string s = "122";
        int ones = 1;
        int len = 3;
        int next = 1;
        int pointer = 2;
        while(len < n)
        {
            if(s[pointer]=='1')
            {
                if(next==1) 
                {
                    if(len+1==n) return ones+1;
                    else{
                        ones++;
                        len++;
                        s.push_back('1');
                    }
                }else{
                    if(len+1==0) return ones;
                    else{
                        len++;
                        s.push_back('2');
                    }
                }
            }
            else
            {
                if(next==1)
                {
                    if(len+1==n) return ones+1;
                    else if(len+2==n) return ones+2;
                    else{
                        ones+=2;len+=2;s.push_back('1');s.push_back('1');
                    }
                }else{
                    if(len+1==n || len+2==n) return ones;
                    else{
                        len+=2;s.push_back('2');s.push_back('2');
                    }
                }
            }
            
            next = next==1?2:1;
            pointer++;
        }
        return ones;
    }
    
    int magicalString01(int n) {
    string S = "122";
    int i = 2;
    while (S.size() < n)
        S += string(S[i++] - '0', S.back() ^ 3);
    return count(S.begin(), S.begin() + n, '1');
}
};