/*
 * Author: Qiang Jia
 * Date: Mar 18, 2015
 * Link: https://leetcode.com/problems/number-of-1-bits/
 * Description:
 *      Write a function that takes an unsigned integer and returns the number of â€?1' bits it has (also known as the Hamming weight (http://en.wikipedia.org/wiki/Hamming_weight)).
 *      For example, the 32-bit integer â€?11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 */

#include <iostream>
#include <stdint.h>
using namespace::std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		for (int i = 0; i < 32; ++i)
			count += n >> i & 0x1;
		return count;
	}
};

void main() {
	Solution solution;
	cout << solution.hammingWeight(11) << endl;
}
