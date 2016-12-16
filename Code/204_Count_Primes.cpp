/*
Count the number of prime numbers less than a non-negative number, n.
*/

/*
the Sieve of Eratosthenes
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n,true);
        
        for(int i = 2; i*i < n; ++i)
        {
            if(is_prime[i])
            {
                for(int j=i*i; j<n; j+=i)
                {
                    is_prime[j] = false;
                }
            }
        }
        
        int cnt = 0;
        
        for(int i = 2; i < n; ++i)
        {
            cnt = (is_prime[i]==true)?++cnt:cnt;
        }
        
        return cnt;
    }
};