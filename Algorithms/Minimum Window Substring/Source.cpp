/*
 * Author: Qiang Jia
 * Date: Sep 26, 2015
 * Link: https://leetcode.com/problems/minimum-window-substring/
 * Description:
 *      Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *      For example,
 *			S = "ADOBECODEBANC"
 *			T = "ABC"
 *      Minimum window is "BANC".
 *      Note:
 *			If there is no such window in S that covers all characters in T, return the empty string "".
 *			If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace::std;

class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> checker;
		for (int i = 0; i < t.size(); ++i)
			contains(checker, t[i]) ? ++checker[t[i]] : checker[t[i]] = 1;
		int p = 0, q = -1;
		pair<int, int> pos(0, INT_MAX);
		while (++q < s.size()) {
			if (contains(checker, s[q]))
				--checker[s[q]];
			if (!containsAll(checker))
				continue;
			while (p < s.size() && (!contains(checker, s[p]) || update(checker, s[p])))
				++p;
			if (q - p < pos.second - pos.first)
				pos.first = p, pos.second = q;
		}
		if (pos.second - pos.first == INT_MAX)
			pos.second = -1;
		return s.substr(pos.first, pos.second - pos.first + 1);
	}
private:
	bool contains(const unordered_map<char, int> &checker, char c) {
		return checker.find(c) != checker.end();
	}
	bool containsAll(const unordered_map<char, int> &checker) {
		return find_if(checker.begin(), checker.end(), [](const pair<char, int> &p) {
			return p.second > 0;
		}) == checker.end();
	}
	bool update(unordered_map<char, int> &checker, char c) {
		bool flag = checker[c] < 0;
		if (flag) ++checker[c];
		return flag;
	}
};

void main()
{
	Solution solution;
	cout << (solution.minWindow("ADOBECODEBANC", "ABC") == "BANC") << endl;
	cout << (solution.minWindow("EDADOBECODEBANC", "ABC") == "BANC") << endl;
	cout << (solution.minWindow("aabaabaaab", "bb") == "baab") << endl;
	cout << (solution.minWindow("bba", "ab") == "ba") << endl;
	cout << (solution.minWindow("a", "a") == "a") << endl;
}
