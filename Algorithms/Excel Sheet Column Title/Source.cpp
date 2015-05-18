/*
 * Author: Qiang Jia
 * Date: Apr 17, 2015
 * Link: https://leetcode.com/problems/excel-sheet-column-title/
 * Description:
 *      Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *      For example:
 *          1 -> A
 *          2 -> B
 *          3 -> C
 *          ...
 *          26 -> Z
 *          27 -> AA
 *          28 -> AB
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace::std;

class Solution {
public:
	string convertToTitle(int n) {
		string s;
		while (n > 0) {
			int tail = n % 26;
			if (tail == 0) {
				tail = 26;
				s = 'Z' + s;
			}
			else {
				char c = 'A' + tail - 1;
				s = c + s;
			}
			n -= tail;
			n /= 26;
		}
		return s;
	}
};

void main()
{
	Solution solution;
	cout << (solution.convertToTitle(1) == "A") << endl;
	cout << (solution.convertToTitle(26) == "Z") << endl;
	cout << (solution.convertToTitle(27) == "AA") << endl;
	cout << (solution.convertToTitle(702) == "ZZ") << endl;
	cout << (solution.convertToTitle(703) == "AAA") << endl;
	cout << (solution.convertToTitle(18278) == "ZZZ") << endl;
}
