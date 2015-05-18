/*
 * Author: Qiang Jia
 * Date: Nov 7, 2013
 * Link: https://leetcode.com/problems/generate-parentheses/
 * Description:
 *		Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *		For example, given n = 3, a solution set is:
 *			"((()))", "(()())", "(())()", "()(())", "()()()"
 */

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace::std;

class Solution {
public:
	void generate(vector<string> &coll, int l, int r, string s) {
		if (!l && !r) {
			coll.push_back(s);
		}
		else {
			if (l) generate(coll, l - 1, r, s + '(');
			if (r > l) generate(coll, l, r - 1, s + ')');
		}
	}
	vector<string> generateParenthesis(int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<string> coll;
		this->generate(coll, n, n, "");
		return coll;
	}
};

void main()
{
	Solution solution;
	vector<string> coll = solution.generateParenthesis(3);
	copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
}
