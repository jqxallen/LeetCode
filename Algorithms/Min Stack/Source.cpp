/*
 * Author: Qiang Jia
 * Date: Apr 14, 2015
 * Link: https://leetcode.com/problems/min-stack/
 * Description:
 *      Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *          1. push(x) -- Push element x onto stack.
 *          2. pop() -- Removes the element on top of the stack.
 *          3. top() -- Get the top element.
 *          4. getMin() -- Retrieve the minimum element in the stack.
 */

#include <iostream>
#include <stack>
#include <algorithm>
using namespace::std;

class MinStack {
public:
	void push(int x) {
		if (s.empty()) {
			s.push(pair<int, int>(x, x));
		}
		else {
			s.push(pair<int, int>(x, min(x, s.top().second)));
		}
	}

	void pop() {
		if (!s.empty())
			s.pop();
	}

	int top() {
		if (s.empty())
			return INT_MIN;
		return s.top().first;
	}

	int getMin() {
		if (s.empty())
			return INT_MIN;
		return s.top().second;
	}
private:
	stack<pair<int, int>> s;
};

void main()
{
	MinStack stack;
	int arr[] = { 3, 2, 5, 4, 1, 7, 6 };
	int res[] = { 3, 2, 2, 2, 1, 1, 1 };
	int n = sizeof(arr) / sizeof(int);
	for (int i = 0; i < n; ++i) {
		stack.push(arr[i]);
	}
	for (int i = n - 1; i >= 0; --i) {
		cout << ((stack.top() == arr[i]) & (stack.getMin() == res[i])) << endl;
		stack.pop();
	}
}
