/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

/*
first matching first char
then match the rest
pay attention to special case
*/


class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0) return 0;
        if(haystack.length()==0 || haystack.length()<needle.length()) return -1;
        for(int i = 0; i <= haystack.length()-needle.length(); ++i)
        {
            if(haystack[i]==needle[0])
            {
                if(haystack.substr(i,needle.length()) == needle) return i;
            }
        }
        return -1;
    }
};