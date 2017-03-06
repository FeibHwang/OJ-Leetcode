/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

/*
DP from top solutions
*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty()||costs[0].empty()) return 0;
        for(int i = 1; i < costs.size(); ++i)
        {
            for(int j = 0; j < costs[0].size(); ++j)
            {
                int left_min = INT_MAX, right_min = INT_MAX;
                for(int c = 0; c < j; ++c) left_min = min(left_min,costs[i-1][c]);
                for(int c = j+1; c < costs[0].size(); ++c) right_min = min(right_min,costs[i-1][c]);
                costs[i][j] += min(left_min,right_min);
            }
        }
        
        int res = INT_MAX;
        for(int j = 0; j < costs[0].size(); ++j)
        {
            res = min(res,costs.back()[j]);
        }
        return res;
    }
    
    
};