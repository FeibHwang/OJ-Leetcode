/********************************************************************************** 
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

* The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
**********************************************************************************/

/********************************************************************************** 
classic implemtation using stack
**********************************************************************************/

class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0 || s.size() % 2 ==1) return false;
        stack<char> stk;
        for(int i = 0; i < s.size(); ++i)
        {
            if(stk.empty()) stk.push(s[i]);
            else{
                char tmp = stk.top();
                if((tmp=='(' && s[i]==')')||(tmp=='[' && s[i]==']')||(tmp=='{' && s[i]=='}')) stk.pop();
                else stk.push(s[i]);
            }
        }
        
        
        return stk.empty();
    }
};