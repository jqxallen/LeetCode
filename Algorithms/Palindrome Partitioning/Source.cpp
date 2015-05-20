/*
 * Author: Qiang Jia
 * Date: Nov 1, 2013
 * Link: https://leetcode.com/problems/palindrome-partitioning/
 * Description:
 *		Given a string s, partition s such that every substring of the partition is a palindrome.
 *		Return all possible palindrome partitioning of s.
 *		For example, given s = "aab",
 *			Return
 *			[
 *				["aa","b"],
 *				["a","a","b"]
 *			]
 */

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace::std;

class Solution {
public:
	bool is_palindrome(const string &s) {
		string t(s);
		reverse(t.begin(), t.end());
		return t == s;
	}
	void partition_recur(string s, vector<vector<string>> &colls, vector<string> coll) {
		for (int i = 1; i <= s.size(); ++i) {
			if (is_palindrome(s.substr(0, i))) {
				coll.push_back(s.substr(0, i));
				if (i == s.size()) colls.push_back(coll);
				else partition_recur(s.substr(i), colls, coll);
				coll.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<vector<string>> colls;
		vector<string> coll;
		partition_recur(s, colls, coll);
		return colls;
	}
};

void main()
{
	string s = "aab";
	Solution solution;
	for (auto &coll : solution.partition(s)) {
		copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, " "));
		cout << endl;
	}
}
