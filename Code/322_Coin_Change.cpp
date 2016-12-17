/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/

/*
DP
transfer function: rec[j] = (tmp > INT_MAX) ? l : tmp
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
	if (amount == 0) return 0;
	long long l = INT_MAX; l+=1;
	vector<long long> rec(amount + 1, l);
	rec[0] = 0;

	for (int i = 0; i < coins.size(); ++i)
	{
		if(coins[i] <= amount)
			rec[coins[i]] = 1;
	}

	for (int j = 0; j < rec.size(); ++j)
	{
		if (rec[j] == l)
		{
			long long tmp = l;
			for (int k = 0; k < coins.size(); ++k)
			{
				if ((j - coins[k] > 0) && (rec[j - coins[k]] != l))
					tmp = min(rec[j - coins[k]] + 1, tmp);
			}
			rec[j] = (tmp > INT_MAX) ? l : tmp;
		}
	}
	return (rec[amount] > INT_MAX) ? -1 : rec[amount];

}
};