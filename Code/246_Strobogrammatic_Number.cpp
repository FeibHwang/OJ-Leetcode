/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

/*
directly construct it's 180 rotation result, and compare
*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        string cmp(num);
        for(int c = 0; c < num.length(); ++c)
        {
            if(cmp[c]=='1' || cmp[c]=='8' || cmp[c]=='0') continue;
            else if(cmp[c]=='6' || cmp[c]=='9')
            {
                cmp[c] = cmp[c]=='6'? '9':'6';
            }
            else return false;
        }
        reverse(cmp.begin(),cmp.end());
        return cmp == num;
    }
};