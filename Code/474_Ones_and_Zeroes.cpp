/*
In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.
Example 1:
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
Example 2:
Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
*/


/*
a tricky DP solution from top solution
first record 1's and 0's in each string
sweep the rec on each string, update the whole matrix everytime a new string add in
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> ones;
        vector<int> zeros;
        for(int i = 0; i < strs.size(); ++i)
        {
            int acc = 0;
            for(int j = 0; j < strs[i].size(); ++j) acc += strs[i][j]-'0';
            ones.push_back(acc);
            zeros.push_back(strs[i].size()-acc);
        }
        
        vector<vector<int>> rec(m+1,vector<int>(n+1,0));
        
        for(int i = 0; i < strs.size(); ++i)
        {
            for(int l = m; l >= zeros[i]; --l)
            {
                for(int k = n; k >= ones[i]; --k)
                {
                    rec[l][k] = max(rec[l][k],rec[l-zeros[i]][k-ones[i]]+1);
                }
            }
        }
        return rec[m][n];
        
    }
};