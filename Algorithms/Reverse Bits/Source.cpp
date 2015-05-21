/*
 * Author: Qiang Jia
 * Date: Mar 18, 2015
 * Link: https://leetcode.com/problems/reverse-bits/
 * Description:
 *      Reverse bits of a given 32 bits unsigned integer.
 *      For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 *      Follow up:
 *          If this function is called many times, how would you optimize it?
 *          Related problem: Reverse Integer (https://leetcode.com/problems/reverse-integer/)
 */

#include <iostream>
#include <stdint.h>
using namespace::std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		int val = 0;
		for (int i = 0; i < 32; val <<= 1, val += n >> i++ & 0x1);
		return val;
	}
};

void main() {
	Solution solution;
	cout << solution.reverseBits(43261596) << endl;
	cout << solution.reverseBits(1) << endl;
}
