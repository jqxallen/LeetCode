/*
 * Author: Qiang Jia
 * Date: Nov 22, 2013
 * Link: https://leetcode.com/problems/search-insert-position/
 * Description:
 *		Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *		You may assume no duplicates in the array.
 *		Here are few examples.
 *			[1,3,5,6], 5 -> 2
 *			[1,3,5,6], 2 -> 1
 *			[1,3,5,6], 7 -> 4
 *			[1,3,5,6], 0 -> 0
 */

#include <iostream>
using namespace::std;

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!n) return 0;
		int i = 0, j = n, k;
		while (i <= j) {
			k = (i + j) / 2;
			if (k && A[k - 1] < target && target < A[k]) return k;
			else if (target < A[k]) if (k == j) return k; else j = k;
			else if (target > A[k]) if (k == i) return k + 1; else i = k;
			else return k;
		}
		return -1;
	}
};
