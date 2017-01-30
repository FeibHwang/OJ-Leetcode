/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

/*
sort by pair first: decreasing order, then by second increasing order
push result: pair second indicates how many item forward
*/

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),[](pair<int,int>x,pair<int,int>y){return x.first==y.first ? x.second < y.second : x.first > y.first;});
        vector<pair<int, int>> res;
        for(int i = 0; i < people.size(); ++i) res.insert(res.begin()+people[i].second,people[i]);
        return res;
    }
};