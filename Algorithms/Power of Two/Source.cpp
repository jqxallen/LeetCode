/*
 * Author: Qiang Jia
 * Date: Jul 6, 2015
 * Link: https://leetcode.com/problems/power-of-two/
 * Description:
 *      Given an integer, write a function to determine if it is a power of two.
 */

#include <iostream>
using namespace::std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n < 1)
			return 0;
		int c = 0;
		for (int i = 0; i < 32; ++i)
			c += (n >> i) & 0x1;
		return c == 1;
	}
};
