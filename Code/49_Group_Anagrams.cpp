/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

/*
the key idea is to know how to decide different order string is same-> sort!
use hash map to count
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;

        for(int i = 0; i < strs.size(); ++i)
        {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        
        for(auto item : mp)
        {
            vector<string> tmp(item.second.begin(),item.second.end());
            result.push_back(tmp);
        }
        return result;
    }
        
};
