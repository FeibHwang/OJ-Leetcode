/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Hint:

You should make use of what you have produced already.
Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
Or does the odd/even status of the number help you in calculating the number of 1s?
*/

/*
watch hint, generate countBits(num) from countBits(num/2)
num is the product of 2, so first make sure num is the product of 2, then cut it
*/

class Solution {
public:
    vector<int> countBits(int num) {
        if(num==0) return {0};
        if(num==1) return {0,1};
        int cnt = 1;
        while(cnt < num)
        {
            cnt = cnt << 1;
        }
        generate_bits(cnt);
        return vector<int>(res.begin(),res.begin()+num+1);
        
    }
    
    vector<int> res;
    
    void generate_bits(int cnt)
    {
        if(cnt == 1)
        {
            res = {0,1};
            return;
        }
        
        generate_bits(cnt/2);
        
        for(int i = 1; i < cnt/2; ++i)
        {
            res.push_back(res[i]+1);
        }
        res.push_back(1);
        
    }
};