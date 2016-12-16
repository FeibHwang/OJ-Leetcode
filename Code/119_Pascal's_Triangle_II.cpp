/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

/*
recurrsive way, very inefficient
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> one_begin = {1};
        if(rowIndex == 0) {return one_begin;}
        vector<int> two_begin = {1,1};
        if(rowIndex == 1) {return two_begin;}
        
        vector<int> one_to_last = getRow(rowIndex - 1);
        vector<int> line_begin = {1};
        for(int num = 0;num < rowIndex - 1; ++ num)
        {
            line_begin.push_back(one_to_last[num] + one_to_last[num+1]);
        }
        line_begin.push_back(1);
        return line_begin;
    }
};