/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
*/

/*
Follow Ugly Number II
since we don't know how many prime number, use vwctor to store index
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> rec = {1};
        vector<int> hold(primes);
        vector<int> index(primes.size(),0);
        while(rec.size()<n)
        {
            for(int i = 0; i < primes.size(); ++i) hold[i] = rec[index[i]]*primes[i];
            int val = INT_MAX;
            for(int i = 0; i < primes.size(); ++i) val = min(val,hold[i]);
            for(int i = 0; i < primes.size(); ++i) if(hold[i]==val) index[i]++;
            rec.push_back(val);
        }
        return rec[n-1];
    }
};