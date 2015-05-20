/*
 * Author: Qiang Jia
 * Date: Nov 1, 2013
 * Link: https://leetcode.com/problems/single-number/
 * Description:
 *      Given an array of integers, every element appears twice except for one. Find that single one.
 *      Note:
 *          Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

#include <vector>
using namespace::std;

class Solution {
public:
	int singleNumber(int A[], int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<int> coll(A, A + n);
		int val = 0;
		for (int i : coll)
			val ^= i;
		return val;
	}
};
