/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

/*
Newton's dichotomy 
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        
        int left = 1;
        int right = x;
        while(left <= right)
        {
            int mid = left + ((right - left)>>1);
            if(x / mid == mid) return mid;
            else if(x / mid > mid) left = mid + 1;
            else right = mid - 1;
        }
        
        return right;
    }
};