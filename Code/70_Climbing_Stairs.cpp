/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/*
I use 2 array for DP
one record the steps which the last step needs 1 step, another needs 2 step
then adding togother get the total ways
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n==0) return 0;
        vector<int> end_one(n+1,0);
        vector<int> end_two(n+1,0);
        
        end_one[1]=1;
        
        for(int i = 2; i <= n; ++i)
        {
            end_two[i] = end_one[i-1];
            end_one[i] = end_one[i-1]+end_two[i-1];
        }
        return end_one[n] + end_two[n];
        
    }
};