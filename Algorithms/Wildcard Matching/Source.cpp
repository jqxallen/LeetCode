/*
 * Author: Qiang Jia
 * Date: Sep 6, 2015
 * Link: https://leetcode.com/problems/wildcard-matching/
 * Description:
 *      Implement wildcard pattern matching with support for '?' and '*'.
 *      '?' Matches any single character.
 *      '*' Matches any sequence of characters (including the empty sequence).
 *      The matching should cover the entire input string (not partial).
 *      The function prototype should be:
 *      bool isMatch(const char *s, const char *p)
 *      Some examples:
 *			isMatch("aa","a") -> false
 *			isMatch("aa","aa") -> true
 *			isMatch("aaa","aa") -> false
 *			isMatch("aa", "*") -> true
 *			isMatch("aa", "a*") -> true
 *			isMatch("ab", "?*") -> true
 *			isMatch("aab", "c*a*b") -> false
 */

#include <iostream>
#include <string>
#include <vector>
using namespace::std;

class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<bool>> m(s.size() + 1, vector<bool>(p.size() + 1, 0));
		m[0][0] = 1;
		for (int i = 0; i < p.size(); ++i)
			m[0][i + 1] = p[i] == '*' && m[0][i];
		for (int i = 0; i < p.size(); ++i) {
			for (int j = 0; j < s.size(); ++j) {
				m[j + 1][i + 1] = (p[i] == s[j] || p[i] == '?') && m[j][i]
					|| p[i] == '*' && (m[j][i] || m[j][i + 1] || m[j + 1][i]);
			}
		}
		return m[s.size()][p.size()];
	}
};

void main()
{
	Solution solution;
	cout << (solution.isMatch("aa", "a") == 0) << endl;
	cout << (solution.isMatch("aa", "aa") == 1) << endl;
	cout << (solution.isMatch("aaa", "aa") == 0) << endl;
	cout << (solution.isMatch("aa", "*") == 1) << endl;
	cout << (solution.isMatch("aa", "a*") == 1) << endl;
	cout << (solution.isMatch("ab", "?*") == 1) << endl;
	cout << (solution.isMatch("aab", "c*a*b") == 0) << endl;
	cout << (solution.isMatch("a", "a*") == 1) << endl;
}
