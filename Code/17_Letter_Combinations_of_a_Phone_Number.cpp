/********************************************************************************** 
* Given a digit string, return all possible letter combinations that the number could represent.

* A mapping of digit to letters (just like on the telephone buttons) is given below.

***************************
|       |2: abc |3: def |
|4: ghi |5: jkl |6: mno |
|7: pqrs|8: tuv |9: wxyz|
***************************

* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
**********************************************************************************/

/********************************************************************************** 
using hash map may be ineffecient, this is just the first thought
**********************************************************************************/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<string>>mp;
        mp['2'] = {"a","b","c"};
        mp['3'] = {"d","e","f"};
        mp['4'] = {"g","h","i"};
        mp['5'] = {"j","k","l"};
        mp['6'] = {"m","n","o"};
        mp['7'] = {"p","q","r","s"};
        mp['8'] = {"t","u","v"};
        mp['9'] = {"w","x","y","z"};
        
        if(digits.size()==0) return {};
        if(digits.size()==1) return mp[digits[0]];
        vector<string> last = letterCombinations(digits.substr(0,digits.size()-1));
        vector<string> tail = mp[digits[digits.size()-1]];
        vector<string> result;
        for(int i = 0; i < last.size(); ++i)
        {
            for(int j = 0; j < tail.size(); ++j)
            {
                result.push_back(last[i]+tail[j]);
            }
        }
        return result;
    }
};