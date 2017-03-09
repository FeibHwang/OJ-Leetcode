/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

/*
partition a valid substr:  
3[a2[c]]  -> <3,a2[c]>
2[abc]3[cd]ef  ->  <2,abc> <3,cd> <1,ef>
pay attention to index 1
*/

class Solution {
public:
    string decodeString(string s) {
        vector<pair<int,string>> dict;
        int cnt = 0,start=0,bracnt = 0;;
        bool count = true;
        
        int fnum = 0;
        while(fnum < s.length() && (s[fnum]<'0'||s[fnum]>'9')) fnum++;
        if(fnum==s.length()) return s;
        if(fnum>0) dict.push_back(make_pair(1,s.substr(0,fnum)));
        
        for(int i = fnum; i < s.length(); ++i)
        {
            if(count && s[i]>='0'&&s[i]<='9')
            {
                cnt = 10*cnt+s[i]-'0';
            }
            if(s[i]=='[')
            {
                count = false;
                if(bracnt==0) start = i;
                bracnt++;
            }
            if(s[i]==']')
            {
                bracnt--;
                if(bracnt==0)
                {
                    dict.push_back(make_pair(cnt,s.substr(start+1,i-start-1)));
                    cout << cnt << endl;
                    count = true;
                    cnt = 0;
                    start = i+1;
                    int t = start;
                    while(t < s.length() && (s[t]<'0'||s[t]>'9')) t++;
                    if(t > start)
                    {
                        dict.push_back(make_pair(1,s.substr(start,t-start)));
                        start = t+1;
                        i = t-1;
                    }
                }
            }
        }
        
        string res = "";
        for(int i = 0; i < dict.size(); ++i)
        {
            string body = decodeString(dict[i].second);
            for(int j = 0; j < dict[i].first; ++j) res += body;
        }
        return res;
    }
};