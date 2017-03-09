/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/


/*
BFS
using a set to avoid duplicate
push original string into queue,

if que.top is valid, push to result
else try to remove any '(' or ')', push into que
*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> rec;
        queue<string> que;
        que.push(s);
        rec.insert(s);
        
        bool found = false;
        
        while(!que.empty())
        {
            s = que.front(); que.pop();
            if(isValid(s))
            {
                res.push_back(s);
                found = true;
            }
            
            if(found) continue;
            
            for(int i = 0; i < s.length(); ++i)
            {
                if(s[i]!='(' && s[i]!=')') continue;
                string test = s.substr(0,i) + s.substr(i+1);
                if(rec.find(test)==rec.end())
                {
                    que.push(test);
                    rec.insert(test);
                }
            }
        }
        return res;
        
    }
    
    bool isValid(string t) {
        int cnt = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '(') ++cnt;
            if (t[i] == ')' && cnt-- == 0) return false;
        }
        return cnt == 0;
    }
};