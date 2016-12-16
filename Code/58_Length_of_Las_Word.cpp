/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

/*
use two pointer to record each word, space, or and of string is the boundary, the last word is the answer

or counting backward, 
pay attention to special case: multi-zero ending or spaces string "    ".
*/
class Solution {
public:
    int lengthOfLastWord01(string s) {
        if(s.empty()){return 0;}
        int lst_num = 0;
        int final = lst_num;
        
    for(int count = 0; count < s.size(); count++)
        {
        if(s[count] != ' ')
        {
           lst_num++;
        }else{
           final = lst_num;
           
           for(int tmp = count; tmp < s.size(); tmp++){
               if(s[tmp] != ' '){lst_num = 1; count = tmp; break;}
           }
        }
        if(count == s.size()-1){final = lst_num;}
    }
        
        return final;
    }
    
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int cnt = s.length()-1;
        int zeros = 0;
        if(s[cnt]==' ')while(cnt >= 0 && s[cnt] == ' ') {cnt--; zeros++;}
        //find first non-empty char at end, record how many space
        while(cnt >= 0 && s[cnt] != ' ') cnt--;
        return s.length()-cnt-1-zeros;
        
    }
};