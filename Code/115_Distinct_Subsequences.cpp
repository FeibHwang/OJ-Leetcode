/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

//http://www.acmerblog.com/leetcode-solution-distinct-subsequences-6358.html
/*
very hard to think about this solution, using 2-D matrix is more reasonable:
http://blog.csdn.net/abcbc/article/details/8978146
*/


class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> rec(t.length()+1,0);
        rec[0]=1;
        for(int i = 0; i < s.length(); ++i)
        {
            for(int j = t.length()-1; j >= 0; j--)
            {
                rec[j+1] += s[i]==t[j] ? rec[j]:0;
            }
        }
        return rec[rec.size()-1];
    }
};