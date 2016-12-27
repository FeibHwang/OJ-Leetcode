/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

/*
DP solution
counting from behind
everytime find a '(', search forward
transfer function: dp[i] = dp[i+1]+2 + ((rt+1 < s.length()) ? dp[rt+1] : 0)
*/



class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()||s.length()==1) return 0;
        
        vector<int> dp(s.length(),0);
        for(int i = s.length()-2; i >= 0; --i)
        {
            if(s[i]=='(')
            {
                int rt = i + dp[i+1] + 1;
                if(rt < s.length() && s[rt]==')') dp[i] = dp[i+1]+2 + ((rt+1 < s.length()) ? dp[rt+1] : 0);
            }
        }
        int res = -1;
        for(int i = 0; i < s.length(); ++i)
        {
            res = res < dp[i] ? dp[i]:res;
        }
        return res;
    }
};