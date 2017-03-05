/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

/*
if the total gas can't cover the total cost, then it will sure be false
if the local gas can't cover local cost, then start from the next station
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty()) return -1;
        if(gas.size()==1) return (gas[0]>=cost[0] ? 0:-1);
        vector<int> rec(gas.size(),0);
        int tot = 0, j = -1, sum = 0;
        for(int i = 0; i < gas.size(); ++i)
        {
            rec[i] = gas[i] - cost[i];
            tot+=rec[i];
            sum+=rec[i];
            if(sum<0) {j = i;sum=0;}
        }
        return tot>=0 ? j+1:-1;
    }
};