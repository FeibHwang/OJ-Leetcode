/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/

/*
hash map 
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,char> r_mp;
        
        for(int i = 0; i < s.size(); ++i)
        {
            if(mp.find(s[i])==mp.end() && r_mp.find(t[i])==r_mp.end())
            {
                mp[s[i]] = t[i];
                r_mp[t[i]] = s[i];
            }
            else if(mp.find(s[i])!=mp.end() && r_mp.find(t[i])!=r_mp.end())
            {
                if(mp[s[i]] == t[i])
                {
                    continue;
                }else{
                    return false;
                }
            }
            else
            {
                return false;
            }
            
        }
        return true;
    }
    

};