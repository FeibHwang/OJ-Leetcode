/********************************************************************************** 
*Given a roman numeral, convert it to an integer.

*Input is guaranteed to be within the range from 1 to 3999.
**********************************************************************************/
/********************************************************************************** 
*Basic fact of Roman: if right is smaller than right, then add, else, minus

**********************************************************************************/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        char cnt= *(s.end()-1);
        int result = mp[cnt];                 //initial
        
        for(int i = s.size()-2; i >= 0; --i)
        {
            result = result + ((mp[s[i]]>=mp[cnt])?mp[s[i]]:-mp[s[i]]);          //left is larger then +, else -
            cnt = s[i];
        }
        return result;
    }
};