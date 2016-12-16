/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/*
"on a line" is not just same line/row, hypotenuse is also count
it's possible to have same point
using hash map to record
key is the slope of one point to target point
*/


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<double,int> mp;
        
        if(points.empty()) return 0;
        else if(points.size()==1) return 1;
        int result = 0;
        
        for(int i = 0; i < points.size(); ++i)
        {
            int x1 = points[i].x;
            int y1 = points[i].y;
            mp.clear();
            mp[(double)INT_MAX]=0;
            int same_point = 0;
            for(int j = 0; j < points.size(); ++j)
            {
                if(i!=j)
                {
                    int x2 = points[j].x;
                    int y2 = points[j].y;
                    if(x1==x2 && y1==y2)
                    {
                        same_point++;
                    }
                    else if(y1==y2)
                    {
                        mp[(double)INT_MAX]++;
                    }
                    else
                    {
                        double k = double(x1-x2) / double(y1-y2);
                        mp[k]++;
                    }
                }
            }
            
            for(auto item : mp)
            {
                result = max(item.second+same_point,result);
            }
            
        }
        

        return result+1;
    }
};