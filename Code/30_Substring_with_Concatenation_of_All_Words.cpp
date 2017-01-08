/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

/*
using two hash map
1 hold words, 1 used as count
once find a match, start from here using count to record, if record match with words perfectly, return index
either match or not, clear map count, keep going
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
	 unordered_map<string, int> dict;
	 for (int i = 0; i < words.size(); ++i) dict[words[i]]++;

	 if (s.length() < words.size()*words[0].length()) return{};
	 unordered_map<string, int> count;
	 int cnt = words.size();
	 int wlen = words[0].size();
	 vector<int> res = {};

	 for (int i = 0; i <= s.length() - words.size()*words[0].length(); ++i)
	 {
		 if (dict.find(s.substr(i, wlen)) != dict.end())
		 {
			 for (int j = 0; j < words.size(); ++j)
			 {
				 string match = s.substr(i + j * wlen, wlen);
				 if (dict.find(match) != dict.end())
				 {
					 count[match]++;
					 if (count[match] > dict[match]) break;
					 else cnt--;
				 }
				 else break;
				 if (cnt == 0 && j == words.size() - 1)
				 {
					 res.push_back(i);
				 }
			 }
			 cnt = words.size();
			 count.clear();
		 }
	 }
	 return res;
 }
};