/*
Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation. 
A string such as "word" contains only the following valid abbreviations:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".
Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits. 
Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.

Example 2:
Given s = "apple", abbr = "a2e":

Return false.
*/

/*
Straight forward solution
directly according to the description
*/

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int pt1 = 0, pt2 = 0;
        while(pt1<word.length() && pt2 < abbr.length())
        {
            if(abbr[pt2]>='a' && abbr[pt2]<='z')
            {
                if(word[pt1++]!=abbr[pt2++]) return false;
            }else{
                int cnt = 0;
                if(abbr[pt2]=='0') return false;
                while(abbr[pt2]>='0' && abbr[pt2]<='9')
                {
                    cnt = 10*cnt+abbr[pt2++]-'0';
                }
                pt1+=cnt;
                continue;
            }
        }
        return pt1==word.length() && pt2==abbr.length();
    }
};