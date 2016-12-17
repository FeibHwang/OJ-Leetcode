/*
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*/

/*
not clearly understand the machenism
*/

class Solution {
public:
    int bulbSwitch(int n) {
        return (int)((n>0)?sqrt(n):0);
    }
    
    int is_prime(int n)    
    {
    if(n<2)  return 0;
    for (int i=2;i*i<=n;i++) 
        {                           
        if(n % i == 0)return 0;
    }
    return 1;
}
};