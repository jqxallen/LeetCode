/*
 * Author: Qiang Jia
 * Date: Nov 22, 2013
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * Description:
 *		Follow up for "Remove Duplicates":
 *			What if duplicates are allowed at most twice?
 *		For example,
 *			Given sorted array nums = [1,1,1,2,2,3],
 *			Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
using namespace::std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!n) return 0;
		int i, j, val = A[0], counter = 1, N = n;
		for (i = j = 1; i < n; ++i) {
			if (A[i] != val) val = A[i], counter = 1, A[j++] = A[i];
			else if (counter == 2) N--;
			else counter++, A[j++] = A[i];
		}
		return N;
	}
};
