/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

/*
using vector to record letter
match with each char in s
everytime when you shift 1 char
simply remove the previous record and add new one, don't need to construct new record
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};
        
        vector<int> rec_board(26,0);
        
        for(int i = 0; i < p.length(); ++i) rec_board[p[i]-'a']++;
        
        
        
        vector<int> rec(26,0);
        for(int i = 0; i < p.length(); ++i) rec[s[i]-'a']++;
        vector<int> res;
        if(rec_board == rec) res.push_back(0);
        
        for(int i = 1; i <= s.length()-p.length(); ++i)
        {
            rec[s[i-1]-'a']--;
            rec[s[i+p.length()-1]-'a']++;
            if(rec == rec_board) res.push_back(i);
        }
        return res;
    }
};