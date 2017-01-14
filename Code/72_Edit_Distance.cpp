/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

/*
DP solution:
from:
http://blog.csdn.net/huaweidong2011/article/details/7727482
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
	vector<vector<int>> rec(word1.size() + 1, vector<int>(word2.size() + 1, 0));
	for (int i = 1; i <= word1.size(); ++i) rec[i][0] = i;
	for (int j = 1; j <= word2.size(); ++j) rec[0][j] = j;

	for (int i = 1; i <= word1.size(); ++i)
	{
		for (int j = 1; j <= word2.size(); ++j)
		{
			rec[i][j] = min(min(rec[i - 1][j] + 1, rec[i][j - 1] + 1),rec[i - 1][j - 1] + (word1[i-1] != word2[j-1]));
		}
	}
	return rec[word1.size()][word2.size()];
}
};