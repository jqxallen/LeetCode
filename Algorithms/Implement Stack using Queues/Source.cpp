/*
 * Author: Qiang Jia
 * Date: Jun 20, 2015
 * Link: https://leetcode.com/problems/implement-stack-using-queues/
 * Description:
 *      Implement the following operations of a stack using queues.
 *			1. push(x) -- Push element x onto stack.
 *			2. pop() -- Removes the element on top of the stack.
 *			3. top() -- Get the top element.
 *			4. empty() -- Return whether the stack is empty.
 *      Notes:
 *			1. You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 *			2. Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 *			3. You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */

#include <queue>
using namespace::std;

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		if (!q1.empty())
			q1.push(x);
		else
			q2.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		if (!q1.empty()) {
			while (q1.size() != 1) {
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
		}
		else {
			while (q2.size() != 1) {
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
		}
	}

	// Get the top element.
	int top() {
		int val;
		if (!q1.empty()) {
			while (q1.size() != 1) {
				q2.push(q1.front());
				q1.pop();
			}
			val = q1.front();
			q2.push(val);
			q1.pop();
		}
		else {
			while (q2.size() != 1) {
				q1.push(q2.front());
				q2.pop();
			}
			val = q2.front();
			q1.push(val);
			q2.pop();
		}
		return val;
	}

	// Return whether the stack is empty.
	bool empty() {
		return q1.empty() && q2.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
};
