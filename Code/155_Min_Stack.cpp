/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

/*
record the min element when push
when pop, if the min pop out, find another min number
*/

class MinStack {
public:
    stack<int> hold;
    int min_num = INT_MAX;
    /** initialize your data structure here. */
    MinStack() {
        NULL;
    }
    
    void push(int x) {
        min_num = min(min_num,x);
        hold.push(x);
    }
    
    void pop() {
        if(hold.top()==min_num)
        {
            stack<int> tmp = hold;
            int min_tmp = INT_MAX;
            tmp.pop();
            while(!tmp.empty())
            {
                min_tmp = min(min_tmp,tmp.top());
                tmp.pop();
            }
            min_num = min_tmp;
        }
        hold.pop();
    }
    
    int top() {
        return hold.top();
    }
    
    int getMin() {
        return min_num;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */