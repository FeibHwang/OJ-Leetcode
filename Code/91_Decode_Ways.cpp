/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

/*
DP solution, use vector to record how many ways can used for decode upto the position of the record matrix
rec[i] = (whether s[i-1]s[i] can form new letter ? 1:0)*rec[i-2] + (whether s[i] can form new letter ? 1:0)*rec[i-1]
*/


class Solution {
public:
    int numDecodings(string s) {
	if (s.empty() || s[0] == '0') return 0;
	if (s.size() == 1) return 1;
	
	vector<int> rec(s.size(), 0);

    rec[0] = 1;
    rec[1] = 1;
	if (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) rec[1] = 2;
	if(s[1]=='0') 
	{
	    if(s[0]=='1' || s[0] == '2') rec[1] = 1;
	    else return 0;
	}

    for(int i = 2; i < s.size();++i)
    {
        int two = s[i-1]=='1'||(s[i-1]=='2' && s[i] <= '6') ? 1:0;
        int one = s[i]<='9' && s[i] > '0' ? 1:0;
        rec[i] = two*rec[i-2] + one*rec[i-1];
    }
    return *(rec.end()-1);
    }
};