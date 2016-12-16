/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

/*
not much to tell
refer to previous question
*/

class Solution {
public:
    int titleToNumber01(string s) {
        if (s.size() == 1) { return int(s[0]) - 64; }
        else {
            return titleToNumber(s.substr(0,s.size()-1)) * 26 + int(s[s.size()-1]) - 64;
        }
        return NULL;
    }
    
    int titleToNumber(string s) {
        int k = int(s[0]) - 64;
        for(int i = 1; i < s.length(); ++i)
        {
            k = (26*k + (int(s[i]) - 64));
        }
        return k;
    }
};