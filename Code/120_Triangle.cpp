/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

/*
Use DP
construct another triangle
transfer function: path_sum[i][k] = (path_sum[i - 1][k - 1] < path_sum[i - 1][k]) ? path_sum[i - 1][k - 1] + triangle[i][k] : path_sum[i - 1][k] + triangle[i][k])
*/

class Solution {
public:
    int minimumTotal01(vector<vector<int>>& triangle) {
	if (triangle.empty()) return 0;

	vector<vector<int>> path_sum;
	path_sum.push_back({ triangle[0][0] });

	for (int i = 1; i < triangle.size(); ++i)
	{
		vector<int> tmp_rec;
		for (int k = 0; k <= i; ++k)
		{
			if (k == 0) tmp_rec.push_back(path_sum[i - 1][0] + triangle[i][0]);
			else if (k == i) tmp_rec.push_back(path_sum[i - 1][k - 1] + triangle[i][k]);
			else tmp_rec.push_back((path_sum[i - 1][k - 1] < path_sum[i - 1][k]) ? path_sum[i - 1][k - 1] + triangle[i][k] : path_sum[i - 1][k] + triangle[i][k]);
		}
		path_sum.push_back(tmp_rec);
	}

	vector<int> last_line = *(path_sum.end() - 1);
	int min_path = last_line[0];
	for (int i = 1; i < last_line.size(); ++i)
		min_path = (min_path < last_line[i]) ? min_path : last_line[i];

	return min_path;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        int i = 1;
        for(; i < triangle.size(); ++i)
        {
            for(int k = 0; k <= i; ++k)
            {
                if(k==0) triangle[i][k] = triangle[i - 1][0] + triangle[i][0];
                else if(k==i) triangle[i][k] = triangle[i - 1][k-1] + triangle[i][k];
                else triangle[i][k] = min(triangle[i - 1][k - 1],triangle[i - 1][k]) + triangle[i][k];
            }
        }
        int result = triangle[i-1][0];
        for(int k = 1; k < i; ++k)
            result = min(result,triangle[i-1][k]);
        return result;
    }
};