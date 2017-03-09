/*
Given a string which contains only lowercase letters, 
remove duplicate letters so that every letter appear once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/

/*
The crucial thing is to preserve lexicographical order
the question is equal to remove letters in s until each letter is unique, and the the result is smallest among all possible substring
solution: 
for each char, record their position, I use hash map with queue to do that
in lexical order 'a'-> 'z' search each letter, if the letter's first position is smaller than the last position of the rest letters, then it's valid, push into result
after that, all the other letter need to erase the position smaller than the searched letter (queue pop)
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
	map<char, queue<int>> mp;
	string rec = "";
	for (int i = 0; i < s.length(); ++i)
	{
		if (mp.find(s[i]) == mp.end()) rec.push_back(s[i]);
		mp[s[i]].push(i);
	}
	sort(rec.begin(), rec.end());

	string result = "";
	while (rec.size()>0)
	{
		for (int i = 0; i < rec.size(); ++i)
		{
			bool can = true;
			for (auto j : mp)
			{
				can = can & mp[rec[i]].front() <= j.second.back();
			}
			if (can)
			{
				result.push_back(rec[i]);
				int del = mp[rec[i]].front();
				mp.erase(rec[i]);
				rec.erase(i, 1);
				for (int ck = 0; ck < rec.size(); ++ck)
				{
					while (mp[rec[ck]].front() < del) mp[rec[ck]].pop();
				}
				break;
			}
		}
	}
	return result;
}
};