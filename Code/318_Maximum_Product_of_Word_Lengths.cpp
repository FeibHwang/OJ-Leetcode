/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

/*
using one int to record the letters in each word
one int contains 32 bit, enough to record 26 letters.
using one int to represent each string, no commom letter: int & int -> 0
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.empty()) return 0;
        vector<int> rec(words.size(),0);
        vector<int> len(rec);
        for(int i = 0; i < words.size(); ++i)
        {
            for(int j = 0; j < words[i].length(); ++j)
            {
                rec[i] = rec[i] | (1<<(words[i][j]-'a'));
            }
            len[i] = words[i].length();
        }
        int res = 0;
        for(int i = 0; i < words.size()-1; ++i)
        {
            for(int j = i+1; j < words.size(); ++j)
            {
                if((rec[i]&rec[j])==0)
                {
                    res = max(res,len[i]*len[j]);
                }
            }
        }
        return res;
    }
};