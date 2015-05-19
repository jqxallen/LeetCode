/*
 * Author: Qiang Jia
 * Date: Apr 17, 2015
 * Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/
 * Description:
 *      Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 *      For example, given the range [5, 7], you should return 4.
 */

#include <iostream>
#include <cmath>
using namespace::std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		if (m == n) return m;
		return m & n & (0xffffffff << int(log((n - m) * 1.0) / log(2.0) + 1));
	}
};

void main()
{
	Solution solution;
	cout << (solution.rangeBitwiseAnd(0, 0) == 0) << endl;
	cout << (solution.rangeBitwiseAnd(3, 3) == 3) << endl;
	cout << (solution.rangeBitwiseAnd(0, 7) == 0) << endl;
	cout << (solution.rangeBitwiseAnd(4, 6) == 4) << endl;
	cout << (solution.rangeBitwiseAnd(5, 6) == 4) << endl;
	cout << (solution.rangeBitwiseAnd(5, 7) == 4) << endl;
	cout << (solution.rangeBitwiseAnd(6, 7) == 6) << endl;
	cout << (solution.rangeBitwiseAnd(11, 15) == 8) << endl;
	cout << (solution.rangeBitwiseAnd(11, 16) == 0) << endl;
	cout << (solution.rangeBitwiseAnd(15, 2147483647) == 0) << endl;
}
