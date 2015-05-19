/*
 * Author: Qiang Jia
 * Date: Dec 7, 2013
 * Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * Description:
 *		Evaluate the value of an arithmetic expression in Reverse Polish Notation (http://en.wikipedia.org/wiki/Reverse_Polish_notation).
 *		Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *		Some examples:
 *			["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *			["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include <vector>
#include <string>
#include <stack>
using namespace::std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		if (tokens.empty()) return 0;
		stack<int> stk;
		int rVal, lVal;
		for (auto s : tokens) {
			try {
				stk.push(stoi(s));
			}
			catch (invalid_argument&) {
				rVal = stk.top(), stk.pop();
				lVal = stk.top(), stk.pop();
				if (s == "+") stk.push(lVal + rVal);
				else if (s == "-") stk.push(lVal - rVal);
				else if (s == "*") stk.push(lVal * rVal);
				else if (s == "/") stk.push(lVal / rVal);
			}
		}
		return stk.top();
	}
};
