/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

/*
record the wordDict, using DFS to search
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(int i = 0; i < wordDict.size(); ++i)
        {
            mp[wordDict[i][0]].push_back(wordDict[i]);
        }
        return wordBreakcheck(s);
    }
    
    unordered_map<char,vector<string>> mp;
    
    bool wordBreakcheck(string s)
    {
        if(s.length()==0) return true;
        if(mp.find(s[0])!=mp.end())
        {
            for(int i = 0; i < mp[s[0]].size(); ++i)
            {
                if(mp[s[0]][i].length()<=s.length())
                {
                    if(mp[s[0]][i].length() == s.length() && mp[s[0]][i] == s) return true;
                    else if(s.substr(0,mp[s[0]][i].length()) == mp[s[0]][i])
                    {
                        if(wordBreakcheck(s.substr(mp[s[0]][i].length()))) return true;
                    }
                }
            }
        }
        return false;
    }
};