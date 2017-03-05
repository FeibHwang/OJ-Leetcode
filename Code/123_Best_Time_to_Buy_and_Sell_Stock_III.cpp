/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/*
from top solution

release2   the left if we sold 2nd stock
hold2      the left if we bought 2nd stock
release1   the left if we sold 1st stock
hold1      the left if we bought 1st stock
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int hold1 = INT_MIN;
        int hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(auto i : prices)
        {
            release2 = max(release2,hold2+i);
            hold2 = max(hold2,release1-i);
            release1 = max(release1,hold1+i);
            hold1 = max(hold1,-i);
        }
        return release2;
    }
};