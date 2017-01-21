/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

/*
using 2 queue
pop: put data in one queue into another queue, exept last one
*/

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(holdque==1) q1.push(x);
        else q2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(holdque==1)
        {
            popout = q1.front();
            q1.pop();
            while(!q1.empty())
            {
                q2.push(popout);
                popout = q1.front();
                q1.pop();
            }
            holdque = 2;
        }else{
            popout = q2.front();
            q2.pop();
            while(!q2.empty())
            {
                q1.push(popout);
                popout = q2.front();
                q2.pop();
            }
            holdque = 1;
        }
    }

    // Get the top element.
    int top() {
        if(holdque==1)
        {
            return q1.back();
        }else{
            return q2.back();
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
    int popout;

    int holdque = 1;
};