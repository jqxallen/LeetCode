/*
 * Author: Qiang Jia
 * Date: Apr 24, 2015
 * Link: https://leetcode.com/problems/reverse-words-in-a-string/
 * Description:
 *		Given an input string, reverse the string word by word.
 *		For example,
 *			Given s = "the sky is blue",
 *			return "blue is sky the".
 *		Update (2015-02-12):
 *			For C programmers: Try to solve it in-place in O(1) space.
 *		Clarification:
 *			What constitutes a word?
 *				A sequence of non-space characters constitutes a word.
 *			Could the input string contain leading or trailing spaces?
 *				Yes. However, your reversed string should not contain leading or trailing spaces.
 *			How about multiple spaces between two words?
 *				Reduce them to a single space in the reversed string.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	void reverseWords(string &s) {
		int i, prev = -1;
		for (i = 0; i < s.size(); ++i) {
			if (prev == -1 && s[i] == ' ')
				prev = i;
			if (prev != -1 && s[i] != ' ') {
				if (prev == 0) {
					s.erase(prev, i - prev);
					i -= i - prev;
				}
				else {
					s.erase(prev, i - prev - 1);
					i -= i - prev - 1;
				}
				prev = -1;
			}
		}
		if (prev != -1)
			s.erase(prev, s.size() - prev);
		reverse(s.begin(), s.end());
		auto first = s.begin(), last = first;
		while ((last = find(first, s.end(), ' ')) != s.end()) {
			reverse(first, last);
			first = last + 1;
		}
		reverse(first, s.end());
	}
};

void main()
{
	vector<string> strings;
	vector<string> results;
	strings.push_back("");
	results.push_back("");
	strings.push_back(" ");
	results.push_back("");
	strings.push_back(" a  ");
	results.push_back("a");
	strings.push_back("the sky is blue");
	results.push_back("blue is sky the");
	strings.push_back("  the  sky is   blue   ");
	results.push_back("blue is sky the");
	Solution solution;
	for (int i = 0; i < strings.size(); ++i) {
		solution.reverseWords(strings[i]);
		cout << (strings[i] == results[i]) << endl;
	}
}
