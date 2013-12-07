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

	system("pause");
}