/*
 * Author: Qiang Jia
 * Date: Apr 24, 2015
 * Link: https://leetcode.com/problems/compare-version-numbers/
 * Description:
 * 		Compare two version numbers version1 and version2.
 * 		If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 * 		You may assume that the version strings are non-empty and contain only digits and the . character.
 * 		The . character does not represent a decimal point and is used to separate number sequences.
 * 		For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 * 		Here is an example of version numbers ordering:
 * 			0.1 < 1.1 < 1.2 < 13.37
 */

#include <iostream>
#include <string>
using namespace::std;

class Solution {
public:
	int compare(string &a, string &b) {
		int l = stoi(a), r = stoi(b);
		return l == r ? 0 : l < r ? -1 : 1;
	}
	int compareVersion(string version1, string version2) {
		string s1, s2;
		int i, j;
		while (true) {
			i = version1.find('.');
			j = version2.find('.');
			s1 = i == string::npos ? version1 : version1.substr(0, i);
			s2 = j == string::npos ? version2 : version2.substr(0, j);
			version1 = version1.substr(s1.size() + (i != string::npos));
			version2 = version2.substr(s2.size() + (j != string::npos));
			if (s1.empty() && s2.empty()) return 0;
			if (s1.empty() && !s2.empty()) {
				if (stoi(s2) != 0) return -1;
				continue;
			}
			if (!s1.empty() && s2.empty()) {
				if (stoi(s1) != 0) return 1;
				continue;
			}
			int val = compare(s1, s2);
			if (val < 0) return -1;
			else if (val > 0) return 1;
		}
	}
};

void main()
{
	Solution solution;
	cout << (solution.compareVersion("01", "1") == 0) << endl;
	cout << (solution.compareVersion("1.0", "1") == 0) << endl;
	cout << (solution.compareVersion("1.0.00", "1") == 0) << endl;
	cout << (solution.compareVersion("1.2", "13.37") == -1) << endl;
	cout << (solution.compareVersion("1.22.3", "1.23") == -1) << endl;
}
