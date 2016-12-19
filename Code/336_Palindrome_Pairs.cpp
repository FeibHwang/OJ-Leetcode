/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/



/*
code from top solutions

using hash map to record revers string and position

look for "" situation

sweeping substring of each string
*/

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string> words) {
    	
    	unordered_map<string, int> mp;
    	vector<vector<int>> res;
    	
    	for(int i = 0; i < words.size(); ++i)
    	{
    	    string tmp = words[i];
    	    reverse(tmp.begin(),tmp.end());
    	    mp[tmp] = i;
    	}
    	
    	if(mp.find("")!=mp.end())
    	{
    	    for(int i = 0; i < words.size(); ++i)
    	    {
    	        if(i!=mp[""] && ispalindrome(words[i]))
    	            res.push_back({mp[""],i});
    	    }
    	}
    	
    	for(int i = 0; i < words.size(); ++i)
    	{
    	    for(int j = 0; j < words[i].size(); ++j)
    	    {
    	        string left = words[i].substr(0,j);
    	        string right = words[i].substr(j,words[i].length()-j);
    	        if(mp.find(left)!=mp.end() && ispalindrome(right) && mp[left]!=i)
    	            res.push_back({i,mp[left]});
    	        if(mp.find(right)!=mp.end() && ispalindrome(left) && mp[right]!=i)
    	            res.push_back({mp[right],i});
    	    }
    	}
    	return res;
    }
    
    bool ispalindrome(string str)
    {
    	int i = 0;
    	int j = str.length()-1;
    	while(i < j)
    	{
    	    if(str[i++]!=str[j--]) return false;
    	}
    	return true;
    }
};