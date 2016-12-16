/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

/*
DP solution
a 2-D matrix
the 1st line/row record whether s3 is match with s1/s2 directely
transfer function: rec[i][j] = (rec[i-1][j] AND (s3[i+j-1]==s1[i-1])) OR (rec[i][j-1] AND (s3[i+j-1]==s2[j-1]));
the idea is, if the true on the matrix is continus from top to bottom, then the final result is true
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        
        int len1=s1.size();
        int len2=s2.size();
        
        vector<vector<bool>> rec(len1+1,vector<bool>(len2+1,0));
        
        rec[0][0]=1;
        
        for(int i = 1; i <= len2; ++i)
        {
            rec[0][i] = rec[0][i-1] && ((s3[i-1]==s2[i-1])?true:false);
        }
        for(int i = 1; i <= len1; ++i)
        {
            rec[i][0] = rec[i-1][0] && ((s3[i-1]==s1[i-1])?true:false);
        }
        
        for(int i = 1; i <= len1; ++i)
        {
            for(int j = 1; j <= len2; ++j)
            {
                rec[i][j] = (rec[i-1][j]&&(s3[i+j-1]==s1[i-1]))||(rec[i][j-1]&&(s3[i+j-1]==s2[j-1]));
            }
        }
        return rec[len1][len2];
    }
};