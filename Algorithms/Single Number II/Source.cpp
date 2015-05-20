/*
 * Author: Qiang Jia
 * Date: Nov 1, 2013
 * Link: https://leetcode.com/problems/single-number-ii/
 * Description:
 *		Given an array of integers, every element appears three times except for one. Find that single one.
 *		Note:
 *			Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
	int singleNumber(int A[], int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<int> coll(A, A + n);
		int val = 0;
		for (int i = 0; i < 32; ++i) {
			int counter = 0;
			int offset = 1 << i;
			for (int ele : coll)
			if (ele & offset)
				counter++;
			if (counter % 3)
				val |= offset;
		}
		return val;
	}
};

void main()
{
	int A[] = { 1, 2, 1, 3, 2, 1, 2 };
	Solution solution;
	cout << solution.singleNumber(A, sizeof(A) / sizeof(int)) << endl;
}
