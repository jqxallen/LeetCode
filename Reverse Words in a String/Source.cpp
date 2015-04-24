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

int main()
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
