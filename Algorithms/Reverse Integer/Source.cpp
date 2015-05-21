/*
 * Author: Qiang Jia
 * Date: Apr 19, 2015
 * Link: https://leetcode.com/problems/reverse-integer/
 * Description:
 *		Reverse digits of an integer.
 *		Example1: x = 123, return 321
 *		Example2: x = -123, return -321
 *		Have you thought about this?
 *			Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 *			If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 *			Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 *			For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 *		Update (2014-11-10):
 *			Test cases had been added to test the overflow behavior.
 */

#include <iostream>
using namespace::std;

class Solution {
public:
	int reverse(int x) {
		int sign = x >= 0 ? 1 : -1;
		x = abs(x);
		int y = 0, t;
		while (x > 0) {
			t = x % 10;
			if (y > (INT_MAX - t) / 10)
				return 0;
			y = y * 10 + t;
			x /= 10;
		}
		return sign * y;
	}
};

void main()
{
	Solution solution;
	cout << (solution.reverse(0) == 0) << endl;
	cout << (solution.reverse(123) == 321) << endl;
	cout << (solution.reverse(-123) == -321) << endl;
	cout << (solution.reverse(1020) == 201) << endl;
	cout << (solution.reverse(INT_MAX) == 0) << endl;
	cout << (solution.reverse(INT_MIN) == 0) << endl;
}
