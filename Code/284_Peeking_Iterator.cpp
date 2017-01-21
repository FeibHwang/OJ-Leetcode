/*
Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].

Call next() gets you 1, the first element in the list.

Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.

You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.

Hint:

Think of "looking ahead". You want to cache the next element.
Is one variable sufficient? Why or why not?
Test your design with call order of peek() before next() vs next() before peek().
For a clean implementation, check out Google's guava library source code.
*/

/*
use a buffer to record next() value, peek only return the buffer
i.e [1,2,3,4]
initiallizing:
    buffer = 1, Iterator pointer -> [2,3,4]
    peek: return buffer
    next: return buffer, buffer = next() = 2, Iterator pointer -> [3,4]
    
need additional val to record whether the buffer is holding value
*/


// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    head = Iterator::next();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return head;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int tmp = head;
	    if(Iterator::hasNext())
	    {
	        head = Iterator::next();
	    }else{
	        valid_head = false;
	    }
	    return tmp;
	}

	bool hasNext() const {
	    return valid_head;
	}
private:
    int head;
    bool valid_head = true;
};