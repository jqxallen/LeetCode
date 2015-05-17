/*
 * Author: Qiang Jia
 * Date: Nov 1, 2013
 * Link: https://leetcode.com/problems/word-break-ii/
 * Description:
 *		Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 *		Return all such possible sentences.
 *		For example, given
 *			s = "catsanddog",
 *			dict = ["cat", "cats", "and", "sand", "dog"].
 *			A solution is ["cats and dog", "cat sand dog"].
 */

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <unordered_set>
using namespace::std;

class Solution {
public:
	void find_sentences(string prefix, string s, const unordered_set<string> &dict, vector<string> &sentences) {
		for (int i = 1; i <= s.length(); ++i) {
			if (dict.find(s.substr(0, i)) != dict.end()) {
				if (i == s.length()) sentences.push_back(prefix + s);
				else find_sentences(prefix + s.substr(0, i) + " ", s.substr(i), dict, sentences);
			}
		}
	}
	bool is_valid(string s, const unordered_set<string> &dict) {
		bool checker[256] = { 0 };
		for (char c : s) checker[(int)c] = 1;
		for (const string &ele : dict) {
			for (char c : ele) {
				if (checker[(int)c])
					checker[(int)c] = 0;
			}
		}
		bool flag = 0;
		for (bool b : checker)
			flag |= b;
		return !flag;
	}
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<string> sentences;
		if (s != "" && dict.size() && this->is_valid(s, dict))
			this->find_sentences("", s, dict, sentences);
		return sentences;
	}
};

void main()
{
	/*string s("catsanddog");
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");*/
	string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
	unordered_set<string> dict;
	for (int i = 1; i <= 10; i++)
		dict.insert(string(i, 'a'));
	Solution solution;
	vector<string> sentences = solution.wordBreak(s, dict);
	copy(sentences.cbegin(), sentences.cend(), ostream_iterator<string>(cout, "\n"));
}
