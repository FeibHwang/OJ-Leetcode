/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

/*
basically same to constructing an AST
or acc based CPU architecture
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> rec;
        for(int i = 0; i < tokens.size(); ++i)
        {
            rec.push(tokens[i]);
            if(rec.top()=="/"||rec.top()=="*"||rec.top()=="+"||rec.top()=="-")
            {
                string oper = rec.top();rec.pop();
                int op1 = stoi(rec.top());rec.pop();
                int op2 = stoi(rec.top());rec.pop();
                int ans;
                if(oper=="+") ans = op1+op2;
                else if (oper=="-") ans = op2-op1;
                else if (oper=="*") ans = op2*op1;
                else ans = op2 / op1;
                rec.push(to_string(ans));
            }
        }
        return stoi(rec.top());
    }
};