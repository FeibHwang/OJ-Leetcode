/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
Back Tracking
for each char in s
find max length substring including the char
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        else if(s.size()==1) return 1;
        
        int pt1 = 0;
        int pt2 = 1;
        int max_length = 1;
        for(;pt2<s.size();++pt2)
        {
            int length = 1;
            for(int k = pt1; k < pt2; k++)
            {
                if(s[k]==s[pt2])
                {
                    length = max(k - pt1 + 1,max(pt2 - k,pt2 - pt1));
                    pt1 = k + 1;
                    break;
                }
            }
            max_length = max(length,max_length);
            if(pt2 == s.size()-1)
            {
                max_length = max(max_length,pt2-pt1+1);
            }
        }
        return max_length;
    }
};