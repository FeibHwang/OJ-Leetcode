/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

/*
using stack to record each word
*/

class Solution {
public:
    void reverseWords(string &s) {
    	if (s.size() == 0) return;
    	stack<string> stk;
    	int i = 0, cnt = 0;
    	while (i<s.size() && s[i] == ' ')
    	{
    		i++;
    		cnt++;
    	}
    	
    	while (cnt < s.size())
    	{
    		if (s[cnt] == ' ')
    		{
    			string tmp(s.begin() + i, s.begin() + cnt);
    			if(tmp!=" " && tmp!="") stk.push(tmp);
    			i = cnt + 1;
    		}
    		cnt++;
    	}
    	if (i != s.size())
    	{
    		string tmp(s.begin() + i, s.end());
    		stk.push(tmp);
    		i = cnt + 1;
    	}
    	s.clear();
    	if (stk.empty()) return;
    	while (!stk.empty())
    	{
    		s += (stk.top() + " ");
    		stk.pop();
    	}
    	s.assign(s.begin(), s.end() - 1);
    }
};