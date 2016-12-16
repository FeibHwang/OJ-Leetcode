/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

/*
similar to full adder
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        
        
        
        vector<int> cin_one = {1};
        vector<int> old_one = digits;
        int length = digits.size();
        int cin = 0;
        if(old_one[length - 1] == 9)
        {
            cin = 1;
            old_one[length - 1] = 0;
        }else{
            old_one[length - 1]++;
            return old_one;
        }
        
        for(int i = length-2;i > -1; --i)
        {
            if(cin == 1)
            {
                if(old_one[i] == 9)
                {
                    old_one[i] = 0;
                }else{
                    cin = 0;
                    old_one[i]++;
                    return old_one;
                }
            }else{
                return old_one;
            }
        }
        if(cin == 1)
        {
            cin_one.insert(cin_one.end(),old_one.begin(),old_one.end());
            return cin_one;
        }
        
        return old_one;
        /*
        int length = digits.size();
        vector<int> old_one = digits;
        vector<int> cin_one = {1};
        
        cin_one.insert(cin_one.end(),old_one.begin(),old_one.end());
        return cin_one;*/
        
        
        
        
    }
};