/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/

class Solution {
public:
    string reverseVowels(string s) {
        string k,l;
        string ss = s;
        for (auto &c : ss) {
		    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			    k = l;
			    l = c + k;
		        }
	        }  
	    int i = 0;
	    for (auto &c : ss) {
		    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
			    c = l[i++];
	        }
        return ss;
    }
};