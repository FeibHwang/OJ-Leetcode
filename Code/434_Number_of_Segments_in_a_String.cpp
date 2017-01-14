/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/

/*
simply add another space on the back
matching pattern: char + spacce as one word
*/

class Solution {
public:
    int countSegments(string s) {
        s.push_back(' ');
        int res = 0;
        for(int i = 1; i < s.length(); ++i)
        {
            if(s[i]==' ' && s[i-1]!=' ') res++;
        }
        return res;
    }
};