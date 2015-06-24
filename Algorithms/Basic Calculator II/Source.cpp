/*
 * Author: Qiang Jia
 * Date: Jun 24, 2015
 * Link: https://leetcode.com/problems/basic-calculator-ii/
 * Description:
 *      Implement a basic calculator to evaluate a simple expression string.
 *      The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
 *      You may assume that the given expression is always valid.
 *      Some examples:
 *			"3+2*2" = 7
 *			" 3/2 " = 1
 *			" 3+5 / 2 " = 5
 *      Note:
 *			Do not use the eval built-in library function.
 */

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int calculate(string s) {
		s += " ";
		int n = s.size(), i, j = -1, k;
		deque<symbol> dqe;
		for (i = 0; i < n; ++i) {
			if (s[i] == ' ')
				continue;
			if (!isdigit(s[i])) {
				j = -1;
				dqe.push_back(symbol(s[i]));
			}
			else {
				if (j == -1)
					j = i;
				if (i + 1 < n && !isdigit(s[i + 1])) {
					k = atoi(s.substr(j, i - j + 1).c_str());
					if (!dqe.empty()) {
						symbol s = dqe.back();
						if (s.c == '*' || s.c == '/') {
							dqe.pop_back();
							k = s.c == '*' ? dqe.back().i * k : dqe.back().i / k;
							dqe.pop_back();
						}
					}
					dqe.push_back(symbol(k));
				}
			}
		}
		while (!dqe.empty()) {
			k = dqe.front().i;
			dqe.pop_front();
			if (dqe.empty())
				break;
			symbol s = dqe.front();
			dqe.pop_front();
			k = s.c == '+' ? k + dqe.front().i : k - dqe.front().i;
			dqe.pop_front();
			dqe.push_front(symbol(k));
		}
		return k;
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
	cout << (solution.calculate("2-1") == 1) << endl;
	cout << (solution.calculate("1-1+1") == 1) << endl;
	cout << (solution.calculate("3+2*2") == 7) << endl;
	cout << (solution.calculate(" 3/2 ") == 1) << endl;
	cout << (solution.calculate(" 3+5 / 2 ") == 5) << endl;
}
