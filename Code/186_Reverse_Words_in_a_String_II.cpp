/*
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
*/

/*
two reverse:
1. reverse the whole string: "the sky is blue"  -->  "eulb si yks eht"
2. identify the word, reverse each word: "eulb si yks eht" --> "blue is sky the"
how to identify word: keep track right boundary, if find a char followed by a space, we found the boundary
how to identify the last word: push another space at the and of the string, pop back when finishing
*/




class Solution {
public:
    void reverseWords(string &s) {
        reverseString(s);
        s.push_back(' ');
        int left = 0,right = 0;
        while(right < s.length()-1)
        {
            if(s[right]!=' ' && s[right+1]==' ')
            {
                reverseword(s,left,right);
                left = right+2;
            }
            right++;
        }
        s.pop_back();
    }
    
    void reverseString(string &s)
    {
        int i = 0;
        int j = s.length()-1;
        while(i < j)
        {
            swap(s[i++],s[j--]);
        }
    }
    
    void reverseword(string &s, int i, int j)
    {
        while(i < j)
        {
            swap(s[i++],s[j--]);
        }
    }
};