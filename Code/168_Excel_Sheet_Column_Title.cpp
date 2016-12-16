/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/


/*
I use recurrsive methord to save writting
it can be more efficient
*/

class Solution {
public:
    string convertToTitle(int n) {
        
        if(n==0) return "";
        
        if(n <=26)
        {
            char tmp = n + 'A'-1;
            string tmp2(1,tmp);
            return tmp2;
        }
        if(n/26!=0 && n%26==0)
        {
            return convertToTitle(n/26-1) + convertToTitle(26);
        }
        return convertToTitle(n/26) + convertToTitle(n%26);
    }
};