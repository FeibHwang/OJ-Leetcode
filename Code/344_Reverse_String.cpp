/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

class Solution {
public:
    string reverseString01(string s) {
        string k,l;
        for (char &c : s){
            k=l;
            l=c+k;
        }
        return l;
    }
    
    string reverseString02(string s) {
        stack<char> stk;
        for (char &c : s){
            stk.push(c);
        }
        
        string result = "";
        while(!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
    
    string reverseString(string s) {
        string result = s;
        for(int i = 0; i <= s.length()/2; ++i)
        {
            result[s.length()-1-i] = s[i];
            result[i] = s[s.length()-1-i];
        }
        return result;
    }
};