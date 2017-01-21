/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/*
Greedy methord
sort: first by begin, then by end
for each overlapping, decide whether to extend the end boundary
for none overlapping, push result, update interval
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()<2) return intervals;
        sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){return a.start == b.start?a.end < b.end:a.start<b.start;});
        Interval cnt(intervals[0]);
        vector<Interval> res;
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(cnt.end >= intervals[i].start)
            {
                cnt.end = max(intervals[i].end,cnt.end);
            }else{
                res.push_back(cnt);
                cnt.start = intervals[i].start;
                cnt.end = intervals[i].end;
            }
        }
        res.push_back(cnt);
        return res;
    }
};