/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/


/*
really nesty algorithm
http://blog.csdn.net/fly_yr/article/details/51134340
*/

class Solution {
public:
    string minWindow(string &source, string &target) {  
        // write your code here  
        if (source.empty() || target.empty())  
            return "";  
  
        int sLen = source.length(), tLen = target.length();  
        vector<int> sHash(256, 0), tHash(256, 0);  
        //2 vector, one store target char
        for (int i = 0; i < tLen; ++i)  
        {  
            ++tHash[target[i]];  
        }//for  
  
        /*记录符合要求的子串的位置，以及找到的字符个数*/  
        int beg = -1, end = sLen, found = 0, minLen = sLen;  
        for (int i = 0, start = i; i < sLen; ++i)  
        {  
            ++sHash[source[i]];  
            /*更新当前找到的字符个数*/  
            if (sHash[source[i]] <= tHash[source[i]])  
                ++found;  
            /*判断是否找到所有字符*/  
            if (found == tLen)  
            {  
                /*将源串开头未出现在目标串的字符跳过*/  
                while (start < i && sHash[source[start]] > tHash[source[start]])  
                {  
                    --sHash[source[start]];  
                    ++start;  
                }//while  
                /*找到符合要求子串的首尾位置start 与 i*/  
                if (i - start < minLen)  
                {  
                    minLen = i - start;  
                    beg = start;  
                    end = i;  
                }//if  
                /*跳过该子串的开头位置，寻找下一个子串*/  
                --sHash[source[start++]];  
                --found;  
            }//if  
        }//for  
  
        /*如果beg值为-1，说明不存在这样的子串*/  
        if (beg == -1)  
            return "";  
        else  
            return source.substr(beg, end - beg + 1);  
    }  
};