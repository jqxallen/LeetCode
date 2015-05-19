/*
 * Author: Qiang Jia
 * Date: Apr 24, 2015
 * Link: https://leetcode.com/problems/integer-to-roman/
 * Description:
 *		Given an integer, convert it to a roman numeral.
 *		Input is guaranteed to be within the range from 1 to 3999.
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace::std;

class Solution {
public:
	string intToRoman(int num) {
		unordered_map<int, char> base;
		base.insert(pair<int, char>(1, 'I'));
		base.insert(pair<int, char>(5, 'V'));
		base.insert(pair<int, char>(10, 'X'));
		base.insert(pair<int, char>(50, 'L'));
		base.insert(pair<int, char>(100, 'C'));
		base.insert(pair<int, char>(500, 'D'));
		base.insert(pair<int, char>(1000, 'M'));
		string s;
		int i = 1000, j, count;
		while (num) {
			count = num / i;
			if (i == 1000) s += string(count, base[i]);
			else if (count == 9) s += base[i], s += base[i * 10];
			else if (count >= 5) s += base[i * 5], s += string(count - 5, base[i]);
			else if (count == 4) s += base[i], s += base[i * 5];
			else if (count > 0) s += string(count, base[i]);
			num %= i;
			i /= 10;
		}
		return s;
	}
};

void main()
{
	Solution solution;
	cout << (solution.intToRoman(22) == "XXII") << endl;
	cout << (solution.intToRoman(621) == "DCXXI") << endl;
	cout << (solution.intToRoman(1904) == "MCMIV") << endl;
	cout << (solution.intToRoman(1954) == "MCMLIV") << endl;
	cout << (solution.intToRoman(1990) == "MCMXC") << endl;
	cout << (solution.intToRoman(2014) == "MMXIV") << endl;
	cout << (solution.intToRoman(2015) == "MMXV") << endl;
}
