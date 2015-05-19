/*
 * Author: Qiang Jia
 * Date: Apr 24, 2015
 * Link: https://leetcode.com/problems/roman-to-integer/
 * Description:
 *		Given a roman numeral, convert it to an integer.
 *		Input is guaranteed to be within the range from 1 to 3999.
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace::std;

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> base;
		base.insert(pair<char, int>('I', 1));
		base.insert(pair<char, int>('V', 5));
		base.insert(pair<char, int>('X', 10));
		base.insert(pair<char, int>('L', 50));
		base.insert(pair<char, int>('C', 100));
		base.insert(pair<char, int>('D', 500));
		base.insert(pair<char, int>('M', 1000));
		int i, val = 0;
		for (i = 0; i < s.size() - 1; ++i) {
			if (base[s[i]] < base[s[i + 1]]) {
				val += base[s[i + 1]] - base[s[i]];
				++i;
			}
			else {
				val += base[s[i]];
			}
		}
		if (i == s.size() - 1)
			val += base[s[i]];
		return val;
	}
};

void main()
{
	Solution solution;
	cout << (solution.romanToInt("DCXXI") == 621) << endl;
}
