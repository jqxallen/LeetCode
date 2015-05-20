/*
 * Author: Qiang Jia
 * Date: Apr 13, 2015
 * Link: https://leetcode.com/problems/factorial-trailing-zeroes/
 * Description:
 *      Given an integer n, return the number of trailing zeroes in n!.
 *      Note:
 *          Your solution should be in logarithmic time complexity.
 */

#include <iostream>
using namespace::std;

class Solution {
public:
	int trailingZeroes(int n) {
		int num = 0;
		while (n >= 5) {
			n /= 5;
			num += n;
		}
		return num;
	}
};

void main()
{
	Solution solution;
	for (int i = 1; i < 51; ++i)
		cout << i << "! has " << solution.trailingZeroes(i) << " trailing zeroes." << endl;
	cout << INT_MAX << "! has " << solution.trailingZeroes(INT_MAX) << " trailing zeroes." << endl;
}
