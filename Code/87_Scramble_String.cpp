/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

/*
record 3 character sequence when sweeping from 0 to end
s1 from 0 to end       rec
s2 from 0 to end       left
s2 from end to 0       right

if(s1==s2) return true

if rec == left, meaning the first i char in s1 and s2 is same, which is one possible break, recurrsively call function apply to first i char string in s1 and s2, and call function to rest.

if rec == right, meaning the first i char in s1 and last i char in s2 is tha same, same like above

pay attention:
1. sweeping from 0 to len-2, leaving one char, because if we attatch the whole string, rec may be equal to left but they are not Scramble, this may causing infinite loop.
2. rec==left and rec==right may occur at same time, and only one can get true, use if statement.
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        if(s1==s2) return true;
        int l = s1.length();
        vector<int> rec(26,0);
        vector<int> left(26,0);
        vector<int> right(26,0);
        for(int i = 0; i < s1.length()-1; ++i)
        {
            rec[s1[i]-'a']++;  left[s2[i]-'a']++; right[s2[l-1-i]-'a']++;
            
            if(rec==left && isScramble(s1.substr(0,i+1),s2.substr(0,i+1)) && isScramble(s1.substr(i+1),s2.substr(i+1)))return true;

            if(rec == right && isScramble(s1.substr(0,i+1),s2.substr(l-1-i)) && isScramble(s1.substr(i+1),s2.substr(0,l-i-1))) return true;
        }
        return false;
    }
};