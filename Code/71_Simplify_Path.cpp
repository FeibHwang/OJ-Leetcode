/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

/*
there are too many corner cases need to be taken care of
so simply record valid
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> rec;
        for(int i = 0; i < path.length();)
        {
            while(i < path.size() && path[i] == '/') ++i;   //ecape '/'
            
            string s = "";
            while(i < path.size() && path[i]!='/') s += path[i++];   //record any thing between the '/'
            
            if(s == ".." && !rec.empty()) rec.pop();                 //check if record is ".."
            else if(s != "" && s != "." && s != "..") rec.push(s);   //don't save invalid
        }
        
        if(rec.empty()) return "/";
        
        string s = "";
        while(!rec.empty())
        {
            s = "/" + rec.top() + s;
            rec.pop();
        }
        return s;
    }
};