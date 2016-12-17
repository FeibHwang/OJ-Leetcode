/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

/*
use hash map to record frequency of each char
if even number char, it will be definalty form palindrome 
if odd number char, number - 1 can be used
*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i < s.length(); ++i)
        {
            mp[s[i]]++;
        }
        int single = 0;
        int cnt = 0;
        for(auto item:mp)
        {
            if(item.second %2 == 0)
            {
                cnt += item.second;
            }else{
                cnt += (item.second - 1);
                single = 1;
            }
        }
        return cnt+single;
    }
};