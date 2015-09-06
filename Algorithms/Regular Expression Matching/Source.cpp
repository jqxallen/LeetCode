/*
 * Author: Qiang Jia
 * Date: Sep 6, 2015
 * Link: https://leetcode.com/problems/regular-expression-matching/
 * Description:
 *      Implement regular expression matching with support for '.' and '*'.
 *      '.' Matches any single character.
 *      '*' Matches zero or more of the preceding element.
 *      The matching should cover the entire input string (not partial).
 *      The function prototype should be:
 *      bool isMatch(const char *s, const char *p)
 *      Some examples:
 *			isMatch("aa","a") ¡ú false
 *			isMatch("aa","aa") ¡ú true
 *			isMatch("aaa","aa") ¡ú false
 *			isMatch("aa", "a*") ¡ú true
 *			isMatch("aa", ".*") ¡ú true
 *			isMatch("ab", ".*") ¡ú true
 *			isMatch("aab", "c*a*b") ¡ú true
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
			m[0][i + 1] = p[i] == '*' && m[0][i - 1];
		for (int i = 0; i < p.size(); ++i) {
			for (int j = 0; j < s.size(); ++j) {
				if (((s[j] == p[i] || p[i] == '.') && m[j][i])
					|| (p[i] == '*' && p[i - 1] == '.' && (m[j + 1][i - 1] || m[j][i + 1]))
					|| (p[i] == '*' && p[i - 1] == s[j] && (m[j + 1][i] || m[j][i + 1]))
					|| (p[i] == '*' && m[j + 1][i - 1] && !m[j + 1][i]))
					m[j + 1][i + 1] = 1;
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
	cout << (solution.isMatch("aa", "a*") == 1) << endl;
	cout << (solution.isMatch("aa", ".*") == 1) << endl;
	cout << (solution.isMatch("ab", ".*") == 1) << endl;
	cout << (solution.isMatch("aab", "c*a*b") == 1) << endl;
	cout << (solution.isMatch("aabbbcd", "a.*bcd") == 1) << endl;
	cout << (solution.isMatch("abcd", "d*") == 0) << endl;
	cout << (solution.isMatch("aaa", "ab*ac*a") == 1) << endl;
}
