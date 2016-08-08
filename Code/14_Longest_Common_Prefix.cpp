/********************************************************************************** 
* Write a function to find the longest common prefix string amongst an array of strings.
**********************************************************************************/

/********************************************************************************** 
* first find the shortest string
* compare the string with every string, if not all matched, match the string without the last letter
**********************************************************************************/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        string compare = strs[0];
        int length = compare.size();
        for(int i = 1; i < strs.size(); ++i)
        {
            if(strs[i].size()<length)
            {
                compare = strs[i];
                length = compare.size();
            }
        }
        
        if(length==0) return "";
        
        while(length >= 0)
        {
            for(int i = 0; i < strs.size(); ++i)
            {
                if(compare!=strs[i].substr(0,length))
                {
                    compare.assign(compare.begin(),compare.end()-1);
                    length--;
                    break;
                }
                if(compare.size()==0 || i==strs.size()-1) return compare;
            }
            
        }
        return "";
    }
};