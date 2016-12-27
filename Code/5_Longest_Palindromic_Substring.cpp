/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/


/*
Manacher’s Algorithm
Very Cool algorithm
memorise this solution
*/


class Solution {
public:
    string longestPalindrome(string s) {
	 string ns = "^#";
	 for (int i = 0; i < s.size(); ++i) { ns += s[i]; ns += "#"; }
	 ns += "$";

	 vector<int> P(ns.length(), 0);
	 int C = 0, L = 0;
	 for (int i = 1; i < ns.length() - 1; ++i)
	 {
		 int R = 2 * C - i;
		 P[i] = (L > i) ? min(L - i, P[R]) : 0;

		 while (ns[i + 1 + P[i]] == ns[i - 1 - P[i]]) P[i]++;

		 if (i + P[i] > L) {
			 C = i;
			 L = i + P[i];
		 }
	 }

	 int maxlen = 0;
	 int centerIndex = 0;
	 for (int i = 0; i < ns.length() - 1; ++i) {
		 if (P[i] > maxlen) {
			 maxlen = P[i];
			 centerIndex = i;
		 }
	 }

	 return s.substr((centerIndex - 1 - maxlen) / 2, maxlen);
 } 
        
};