/*
 * Author: Qiang Jia
 * Date: Dec 7, 2013
 * Link: https://leetcode.com/problems/text-justification/
 * Description:
 *		Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 *		You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 *		Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 *		For the last line of text, it should be left justified and no extra space is inserted between words.
 *		For example,
 *			words: ["This", "is", "an", "example", "of", "text", "justification."]
 *			L: 16.
 *			Return the formatted lines as:
 *			[
 *			   "This    is    an",
 *			   "example  of text",
 *			   "justification.  "
 *			]
 *		Note:
 *			Each word is guaranteed not to exceed L in length.
 *		Corner Cases:
 *			A line other than the last line might contain only one word. What should you do in this case?
 *			In this case, that line should be left-justified.
 */

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace::std;

class Solution {
public:
	string fill_spaces(int n) {
		string s(n, ' ');
		return s;
	}
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> results;
		int i, j = 0, real_len = 0, total_len = 0;
		string line;
		for (i = 0; i < words.size(); ++i) {
			if (total_len + words[i].size() + 1 <= L)
				real_len += words[i].size(), total_len += words[i].size() + 1;
			else if (total_len + words[i].size() <= L)
				real_len += words[i].size(), total_len += words[i].size();
			else {
				line = "";
				int spaces = L - real_len, slots = i - j - 1, n;
				for (int k = j; k < i; ++k) {
					line += words[k];
					if (k != i - 1) {
						n = (spaces + slots - 1) / slots, spaces -= n, slots--;
						line += this->fill_spaces(n);
					}
				}
				if (j == i - 1) line += this->fill_spaces(spaces);
				results.push_back(line);
				j = i, real_len = words[i].size(), total_len = real_len + 1;
			}
		}
		line = "";
		for (int k = j; k < words.size(); ++k) {
			if (k != j) line += " ";
			line += words[k];
		}
		line += this->fill_spaces(L - real_len - (words.size() - 1 - j));
		results.push_back(line);
		return results;
	}
};

void main()
{
	vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
	int L = 16;
	words = { "Listen", "to", "many,", "speak", "to", "a", "few." }, L = 6;
	words = { "What", "must", "be", "shall", "be." }, L = 12;
	Solution solution;
	vector<string> results = solution.fullJustify(words, L);
	copy(results.cbegin(), results.cend(), ostream_iterator<string>(cout, "|\n"));
}
