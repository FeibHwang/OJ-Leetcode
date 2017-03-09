/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.
 
For example, the above binary watch reads "3:25".
Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
Example: 
Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
*/

/*
very clever way to do it:
iterate every possible combination,
counting the bits
*/


class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int i = 0; i < 12; ++i)
        {
            for(int j = 0; j < 60; ++j)
            {
                if(countBit(i) + countBit(j) == num)
                {
                    string h = to_string(i);
                    string m;
                    if(j==0) m = "00";
                    else if(j <= 9) m = "0" + to_string(j);
                    else m = to_string(j);
                    res.push_back(h + ":" +m);
                }
            }
        }
        return res;
    }
    
    int countBit(int i)
     {
    	 int cnt = 0;
    	 cnt += ((i & 1) != 0);
    	 cnt += ((i & 2) != 0);
    	 cnt += ((i & 4) != 0);
    	 cnt += ((i & 8) != 0);
    	 cnt += ((i & 16) != 0);
    	 cnt += ((i & 32) != 0);
    	 return cnt;
     }
};