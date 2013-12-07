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