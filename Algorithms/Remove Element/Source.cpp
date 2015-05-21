/*
 * Author: Qiang Jia
 * Date: Nov 14, 2013
 * Link: https://leetcode.com/problems/remove-element/
 * Description:
 *		Given an array and a value, remove all instances of that value in place and return the new length.
 *		The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
using namespace::std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!n) return 0;
		int i, j = n - 1, N = n;
		for (i = 0; i <= j; ++i) {
			if (A[i] == elem)
				A[i--] = A[j--], N--;
		}
		return N;
	}
};
