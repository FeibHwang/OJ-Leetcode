/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].

Hint:

Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.
*/

/*
construct recursively, the result is different for even/odd n
even: construct n-2, add "00"/"11"/"69"/"88"/"96" in the midde
odd: construct n-1, add "0"/"1"/"8" in  te middel
*/

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if(n<=0) return {};
        if(n==1) return {"0","1","8"};
        if(n==2) return {"11","69", "88", "96"};
        vector<string> res;
        vector<string> ress;
        if(n%2==0)
        {
            res = findStrobogrammatic(n-2);
            for(int i = 0; i < res.size(); ++i)
            {
                ress.push_back(res[i].substr(0,n/2-1) + "00" + res[i].substr(n/2-1));
                ress.push_back(res[i].substr(0,n/2-1) + "11" + res[i].substr(n/2-1));
                ress.push_back(res[i].substr(0,n/2-1) + "69" + res[i].substr(n/2-1));
                ress.push_back(res[i].substr(0,n/2-1) + "88" + res[i].substr(n/2-1));
                ress.push_back(res[i].substr(0,n/2-1) + "96" + res[i].substr(n/2-1));
            }
        }else{
            res = findStrobogrammatic(n-1);
            for(int i = 0; i < res.size(); ++i)
            {
                ress.push_back(res[i].substr(0,n/2) + "0" + res[i].substr(n/2));
                ress.push_back(res[i].substr(0,n/2) + "1" + res[i].substr(n/2));
                ress.push_back(res[i].substr(0,n/2) + "8" + res[i].substr(n/2));
            }
        }
        return ress;
    }
};