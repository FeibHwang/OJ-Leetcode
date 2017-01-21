/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/*
pretty brute forse way:
generate n-1
insert another (), if it's unique, push result
*/


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n==0) return {};
        if (n==1) return {"()"};
        vector<string> res;
        unordered_map<string,bool> mp;
        vector<string> rec = generateParenthesis(n-1);
        for(int i = 0; i < rec.size(); ++i)
        {
            for(int j = 0; j < 2*n-2; ++j)
            {
                string tmp = rec[i].substr(0,j) + "()" + rec[i].substr(j);
                if(mp.find(tmp)==mp.end())
                {
                    mp[tmp] = true;
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};



/*
dfs solution:
construct dfs function
left right indicates number of left/right Parentheses
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs(n,0,0);
        return res;
    }
    
    void dfs(int n, int left, int right)
    {
        if(left == n)
        {
            string s(hold);
            s.append(n-right,')');
            res.push_back(s);
            return;
        }
        
        hold.push_back('(');
        dfs(n,left+1,right);
        hold.pop_back();
        
        if(left > right)
        {
            hold.push_back(')');
            dfs(n,left,right+1);
            hold.pop_back();
        }
        
    }
    
    vector<string> res;
    string hold;
};