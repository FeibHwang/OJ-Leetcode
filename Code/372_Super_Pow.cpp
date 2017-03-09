/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024
*/


/*
/*
Basic fact:
1. (A*B) mod C = ((A mod C) * (B mod C)) mod C
2. k^25 = k^20 * k^5 = (k^2 * k^2..10times.. * k^2) * k^5

result

A^[3,4,5] mod 1337
=(((A mod 1337)^5) mod 1337) * ((A^[3,4] mod 1337) * (A^[3,4] mod 1337) * (A^[3,4] mod 1337) * ...) mod 1337

remember: single pow may goes beyond limit!
*/

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int k = a % 1337;   //1230
        if(k==0) return 0;
        if(b.empty()) return 1;  //3,2
        
        int last = b.back();  //3
        b.pop_back(); //{3}
        int left_single = superPow(k,b); //{1230,3}
        int right = powmod(k,last);
        
        int left = 1;
        for(int i = 0; i < 10; ++i)
        {
            left = (left * left_single)%1337;
        }
        return (left*right)%1337;
    }
    
    int powmod(int k, int m)
    {
        if(m==0) return 1;
        if(m==1) return k%1337;
        if(m%2==0) return ((powmod(k,m/2)%1337)* (powmod(k,m/2)%1337))%1337;
        return ((powmod(k,m-1)%1337)*k)%1337;
        
    }
};
*/