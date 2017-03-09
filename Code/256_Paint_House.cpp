/*
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
*/

//dp from top solution

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty()||costs[0].empty()) return 0;
        for(int i = 1; i < costs.size(); ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                if(j==0) costs[i][j] += min(costs[i-1][1],costs[i-1][2]);
                else if(j==1) costs[i][j] += min(costs[i-1][0],costs[i-1][2]);
                else costs[i][j] += min(costs[i-1][0],costs[i-1][1]);
            }
        }
        return min(costs.back()[0],min(costs.back()[1],costs.back()[2]));
    }
    
};