/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

/*
dual hash map, char->string, string->char
maybe I can use only one hash map
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        if(str.empty()){return false;}
        int start = 0;
        vector<string> word;
        
        for (int i = start; i<str.size(); ++i)
	    {
		    if (str[i] == ' ')
		    {
			    word.push_back(str.substr(start, i - start));
			    start = ++i;
		    }
		    if (i == str.size() - 1)
			    word.push_back(str.substr(start, i - start+1));
	    }
        
        if(pattern.size()!=word.size()) return false;
        
        unordered_map<char,string> mp;
        unordered_map<string,char> r_mp;
        
        for(int i = 0; i < word.size(); ++i)
        {
            if(mp.find(pattern[i])==mp.end() && r_mp.find(word[i])==r_mp.end())
            {
                    mp[pattern[i]]=word[i];
                    r_mp[word[i]]=pattern[i];
            }
            else if(mp[pattern[i]]!=word[i] || r_mp[word[i]]!=pattern[i])
                return false;
        }
        return true;
        
    }
};