/*
 * Author: Qiang Jia
 * Date: May 6, 2015
 * Link: https://leetcode.com/problems/isomorphic-strings/
 * Description:
 *		Given two strings s and t, determine if they are isomorphic.
 *		Two strings are isomorphic if the characters in s can be replaced to get t.
 *		All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 *		For example,
 *			Given "egg", "add", return true.
 *			Given "foo", "bar", return false.
 *			Given "paper", "title", return true.
 *		Note:
 *			You may assume both s and t have the same length.
 */

#include <string>
#include <bitset>
#include <unordered_map>
using namespace::std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;
		bitset<256> checker;
		unordered_map<char, char> cache;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			if (cache.find(s[i]) == cache.end()) {
				if (checker.test(t[i]))
					return false;
				cache.insert(pair<char, char>(s[i], t[i]));
				checker.set(t[i]);
			}
			else if (cache[s[i]] != t[i]) {
				return false;
			}
		}
		return true;
	}
};
