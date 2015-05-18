/*
 * Author: Qiang Jia
 * Date: Apr 17, 2015
 * Link: https://leetcode.com/problems/excel-sheet-column-number/
 * Description:
 *      Related to question Excel Sheet Column Title (https://leetcode.com/problems/excel-sheet-column-title/)
 *      Given a column title as appear in an Excel sheet, return its corresponding column number.
 *      For example:
 *          A -> 1
 *          B -> 2
 *          C -> 3
 *          ...
 *          Z -> 26
 *          AA -> 27
 *          AB -> 28
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace::std;

class Solution {
public:
	int titleToNumber(string s) {
		int res = 0, i = 0;
		for_each(s.crbegin(), s.crend(), [&](char c){
			res += pow(26.0, i++) * (c - 'A' + 1);
		});
		return res;
	}
};

void main()
{
	Solution solution;
	cout << (solution.titleToNumber("A") == 1) << endl;
	cout << (solution.titleToNumber("Z") == 26) << endl;
	cout << (solution.titleToNumber("AA") == 27) << endl;
	cout << (solution.titleToNumber("ZZ") == 702) << endl;
	cout << (solution.titleToNumber("AAA") == 703) << endl;
	cout << (solution.titleToNumber("ZZZ") == 18278) << endl;
}
