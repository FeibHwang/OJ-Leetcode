/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

/*
mirror reflect:
the left half of graycode n is gracode n-1
the right half is the mirror of gracode n-1 plus 2^(n-1)
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0) return {0};
        if(n==1) return {0,1};
        vector<int> rec = grayCode(n-1);
        int add = 1 << (n-1);
        for(int i = rec.size()-1; i>=0; --i)
        {
            rec.push_back(rec[i]+add);
        }
        return rec;
    }
};