/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

/*
key issue is about *
if no *, just match single char: s[head]==p[head] && isMatch(s[rest],p[rest])
if there is * in p, keep matching s until match failure
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p[0] == '\0') return s[0] =='\0';
        if(p.size()>1 && p[1]=='*')
        {
            int sbegin = 0;
            while(sbegin < s.length() && (s[sbegin]==p[0] || (p[0]=='.'))){
                if(isMatch(s.substr(++sbegin),p.substr(2))) return true;
            }
            return isMatch(s,p.substr(2));
        }else{
            if(s[0]==p[0] || (p[0]=='.'&&s[0]!='\0')) return isMatch(s.substr(1),p.substr(1));
            else return false;
        }
        return false;
    }
};