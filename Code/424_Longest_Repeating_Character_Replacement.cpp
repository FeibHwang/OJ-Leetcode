/*
Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.
Note:
Both the string's length and k will not exceed 104. 
Example 1: 
Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.

Example 2: 
Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/


/*
http://www.cnblogs.com/grandyang/p/5999050.html

sliding window method:
keep track the number of most frequent num cnt
the window length - cnt = latters need to be changed
once the required changed number goes beyond k
shrink the window by plus left boundary
every time extend right boundary, update max length
*/


class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty()) return 0;
        int left = 0, cnt = 0, res = 0;
        vector<int> rec(26,0);
        for(int i = 0; i < s.length(); i++)
        {
            cnt = max(cnt,++rec[s[i]-'A']);
            while(i-left+1-cnt > k)
            {
                --rec[s[left++]-'A'];
                
            }
            res = max(res,i-left+1);
        }
        return res;
    }
    

    
};