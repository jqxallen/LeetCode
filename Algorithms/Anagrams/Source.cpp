/*
 * Author: Qiang Jia
 * Date: Apr 17, 2015
 * Link: https://leetcode.com/problems/anagrams/
 * Description:
 *      Given an array of strings, return all groups of strings that are anagrams.
 *      Note:
 *          All inputs will be in lower-case.
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
#include <algorithm>
using namespace::std;

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<string> v;
		unordered_map<int, vector<string>> cache;
		hash<string> hash;
		for (auto it = strs.cbegin(); it != strs.cend(); ++it) {
			string s(*it);
			sort(s.begin(), s.end());
			cache[hash(s)].push_back(*it);
		}
		for (auto it = cache.cbegin(); it != cache.cend(); ++it) {
			if (it->second.size() >= 2)
				copy(it->second.cbegin(), it->second.cend(), back_inserter(v));
		}
		return v;
	}
};
