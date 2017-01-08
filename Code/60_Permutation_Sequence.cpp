/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
*/

/*
Solution from top Solutions
Cantor expansion: https://en.wikipedia.org/wiki/Cantor_function
Just memorize it!!!!!
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        int i,j,f = 1;
        string s(n,'0');
        for(i=1;i<=n;++i)
        {
            f*=i;
            s[i-1] += i;
        }
        
        for(i = 0,k--; i < n; ++i)
        {
            f /= n-i;
            j = i+k/f;
            char c = s[j];
            for(;i<j;j--) s[j] = s[j-1];
            k %= f;
            s[i] = c;
        }
        
        return s;
    }
};