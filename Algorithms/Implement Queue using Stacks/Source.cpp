/*
 * Author: Qiang Jia
 * Date: Jul 7, 2015
 * Link: https://leetcode.com/problems/implement-queue-using-stacks/
 * Description:
 *      Implement the following operations of a queue using stacks.
 *			1. push(x) -- Push element x to the back of queue.
 *			2. pop() -- Removes the element from in front of queue.
 *			3. peek() -- Get the front element.
 *			4. empty() -- Return whether the queue is empty.
 *      Notes:
 *			1. You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 *			2. Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 *			3. You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 */

#include <iostream>
#include <stack>
using namespace::std;

class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		s1.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		if (!s2.empty())
			s2.pop();
	}

	// Get the front element.
	int peek(void) {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return s1.empty() && s2.empty();
	}
private:
	stack<int> s1;
	stack<int> s2;
};
