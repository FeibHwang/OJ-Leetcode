/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

/*
very intreseting idea:
let string t = str+str
delete 1st and last char
if t still contains str, then it is repeated!!
*/

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        string test = str+str;
        for(int i = 1; i < str.length(); ++i)
        {
            if(test[i] == str[0]) //just improve efficiency
                if(test.substr(i,str.length())==str) return true;
        }
        return false;
    }
};