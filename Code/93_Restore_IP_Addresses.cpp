/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/


/*
dp solution:
dfs function record string and next cutting position
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4) return res;
        dfs(s,0);
        return res;
    }
    
    vector<string> res;
    vector<string> hold;
    
    void dfs(string s, int cut)
    {
        if(hold.size()==4 && cut == s.size())
        {
            res.push_back(hold[0] + "." + hold[1] + "." + hold[2] + "." + hold[3]);
            return;
        }
        
        if (s.size() - cut > (4 - hold.size()) * 3)   return;  //decide whether the rest can form valid address 
        if (s.size() - cut < (4 - hold.size()))       return;
        
        int cnt = 0;
        for(int i = cut; i < cut+3 && i <s.size(); ++i)
        {
            cnt = 10*cnt + (int)(s[i] - '0');
            
            if(cnt < 0 || cnt > 255) continue;
            hold.push_back(s.substr(cut,i-cut+1));
            dfs(s,1+i);
            hold.pop_back();
            
            if(cnt == 0) break;
        }
    }
};
