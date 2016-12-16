/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
*/

/*
Same strategy
accumulating the local matrix sum
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        
        prices.push_back(-1);
        vector<int> local_maxProfit(1,0);
        
        int low = prices[0];
        int max_profit = 0;
        
        for(int i = 1; i < prices.size();++i)
        {
            if(prices[i]<=prices[i-1])
            {
                low = prices[i];
                local_maxProfit.push_back(0);
            }else{
                
                local_maxProfit.push_back(prices[i]-low);
            }
        }
        
        int local_part_sum = 0;
        
        
        for(int j = 1; j < prices.size(); ++j)
        {
            if(local_maxProfit[j] > local_maxProfit[j-1]) continue;
            
            local_part_sum += local_maxProfit[j-1];
        }
        
        return local_part_sum;
    }
};