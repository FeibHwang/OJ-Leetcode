/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
*/

/*
not much to tell
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = n & 1;
        for(int i = 0; i < 31; ++i)
        {
            n >>= 1;
            res <<= 1;
            res += n & 1;
        }
        return res;
        
    }
};