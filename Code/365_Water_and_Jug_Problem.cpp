/*
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)

Input: x = 3, y = 5, z = 4
Output: True
Example 2:

Input: x = 2, y = 6, z = 5
Output: False
*/

/*
equal to find z = m * x + n * y possibility
ax + by = d => d = gcd(x, y)
*/



class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false;
        if(z == 0) return true;
        int k = gcd(x,y);
        return z % k == 0;
    }
    
    int gcd(int x, int y)
    {
        return y == 0 ? x : gcd(y, x%y);
    }
    //http://www.cnblogs.com/grandyang/p/5628836.html
    //if gcd(x,y)%z==0
};