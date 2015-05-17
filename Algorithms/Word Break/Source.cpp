/*
 * Author: Qiang Jia
 * Date: Nov 1, 2013
 * Link: https://leetcode.com/problems/word-break/
 * Description:
 *		Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *		For example, given
 *			s = "leetcode",
 *			dict = ["leet", "code"].
 *			Return true because "leetcode" can be segmented as "leet code".
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace::std;

class Solution {
public:
	bool find_separator(string s, unordered_set<string> &dict) {
		for (int i = 1; i <= s.length(); ++i) {
			if (dict.find(s.substr(0, i)) != dict.end()) {
				if (i == s.length()) return 1;
				else if (find_separator(s.substr(i), dict)) return 1;
			}
		}
		return 0;
	}
	bool is_valid(string s, const unordered_set<string> &dict) {
		bool checker[256] = { 0 };
		for (char c : s) checker[(int)c] = 1;
		for (const string &ele : dict)
		for (char c : ele)
		if (checker[(int)c])
			checker[(int)c] = 0;
		bool flag = 0;
		for (bool b : checker) flag |= b;
		return !flag;
	}
	bool wordBreak(string s, unordered_set<string> &dict) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (s != "" && dict.size() && this->is_valid(s, dict))
			return this->find_separator(s, dict);
		return 0;
	}
};

void main()
{
	string s("leetcode");
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	Solution solution;
	cout << solution.wordBreak(s, dict) << endl;
}
