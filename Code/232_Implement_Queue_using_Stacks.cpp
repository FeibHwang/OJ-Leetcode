/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

/*
keep two stack
one keep reverse order
when pop, one stack goes to another
use signal bit to indicate where the data locats
*/

class Queue {
public:

	stack<int> sequence;                 //store normal order of the sequence
	stack<int> reverse_sequence;         //store reverse order of the sequence
	bool status = true;                  //indicate where is the data locate, true=sequence, false=reverse


										 // Push element x to the back of queue.
	void push(int x) {
		if (status)
		{
			sequence.push(x);
		}
		else {
			move_data2();
			sequence.push(x);
			status = true;
		}
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (!sequence.empty() || !reverse_sequence.empty())
		{
			if (status)
			{
				move_data1();
				reverse_sequence.pop();
				status = false;
			}
			else {
				reverse_sequence.pop();
			}
		}
	}

	// Get the front element.
	int peek(void) {
		if (!sequence.empty() || !reverse_sequence.empty())
		{
			if (status)
			{
				move_data1();
				status = false;
				return reverse_sequence.top();
			}
			else {
				return reverse_sequence.top();
			}
		}
		return NULL;
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return sequence.empty() && reverse_sequence.empty();
	}

	void move_data1(void)     //move data from one stack to another(reverse)
	{
		while (!sequence.empty())
		{
			int tmp = sequence.top();
			sequence.pop();
			reverse_sequence.push(tmp);
		}
	}

	void move_data2(void)     //move data from one stack to another(reverse)
	{
		while (!reverse_sequence.empty())
		{
			int tmp = reverse_sequence.top();
			reverse_sequence.pop();
			sequence.push(tmp);
		}
	}

};