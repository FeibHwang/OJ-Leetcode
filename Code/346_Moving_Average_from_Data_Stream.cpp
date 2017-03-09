/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

/*
I use queue for window porpuse
*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        cap = size;
        hold = 0;
        sum = 0;
    }
    
    double next(int val) {
        que.push(val);
        sum+=val;
        if(hold==cap)
        {
            sum -= que.front();
            que.pop();
        }else{
            hold++;
        }
        return ((double)sum)/((double)hold);
    }
    
private:
    queue<int> que;
    int cap;
    int hold;
    int sum;
};