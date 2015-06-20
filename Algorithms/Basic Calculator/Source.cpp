/*
 * Author: Qiang Jia
 * Date: Jun 20, 2015
 * Link: https://leetcode.com/problems/basic-calculator/
 * Description:
 *      Implement a basic calculator to evaluate a simple expression string.
 *      The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
 *      You may assume that the given expression is always valid.
 *      Some examples:
 *			"1 + 1" = 2
 *			" 2-1 + 2 " = 3
 *			"(1+(4+5+2)-3)+(6+8)" = 23
 *      Note:
 *			Do not use the eval built-in library function.
 */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int calculate(string s) {
		s += " ";
		int n = s.size(), i, j = -1, k;
		stack<symbol> stk;
		for (i = 0; i < n; ++i) {
			if (s[i] == ' ')
				continue;
			if (!isdigit(s[i])) {
				j = -1;
				if (s[i] != ')')
					stk.push(symbol(s[i]));
				else {
					symbol s = stk.top();
					stk.pop(), stk.pop();
					if (stk.empty() || stk.top().c == '(')
						stk.push(s);
					else {
						symbol ss = stk.top();
						stk.pop();
						ss = ss.c == '+' ? symbol(stk.top().i + s.i) : symbol(stk.top().i - s.i);
						stk.pop();
						stk.push(ss);
					}
				}
			}
			else {
				if (j == -1)
					j = i;
				if (i == n - 1) {
					k = atoi(s.substr(j, i - j + 1).c_str());
					stk.push(symbol(k));
				}
				else if (i + 1 < n && !isdigit(s[i + 1])) {
					k = atoi(s.substr(j, i - j + 1).c_str());
					if (stk.empty() || stk.top().c == '(')
						stk.push(symbol(k));
					else {
						symbol s = stk.top();
						stk.pop();
						s = s.c == '+' ? symbol(stk.top().i + k) : symbol(stk.top().i - k);
						stk.pop();
						stk.push(s);
					}
				}
			}
		}
		return stk.top().i;
	}
private:
	struct symbol {
		int i;
		char c;
		symbol(int I) : i(I), c('.') {}
		symbol(char C) : i(0), c(C) {}
	};
};

void main()
{
	Solution solution;
	cout << (solution.calculate("1") == 1) << endl;
	cout << (solution.calculate("2147483647") == 2147483647) << endl;
	cout << (solution.calculate("1 + 1") == 2) << endl;
	cout << (solution.calculate(" 2-1 + 2 ") == 3) << endl;
	cout << (solution.calculate("2-(5-6)") == 3) << endl;
	cout << (solution.calculate("(1+(4+5+2)-3)+(6+8)") == 23) << endl;
	cout << (solution.calculate("(1+(4+5+2)-3)-(6-8)+(2+9)") == 22) << endl;
}
