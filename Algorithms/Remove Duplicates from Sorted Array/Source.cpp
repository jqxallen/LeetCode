/*
 * Author: Qiang Jia
 * Date: Nov 13, 2013
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Description:
 *		Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *		Do not allocate extra space for another array, you must do this in place with constant memory.
 *		For example,
 *			Given input array nums = [1,1,2],
 *			Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <iterator>
using namespace::std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!n) return 0;
		int N = n, val = A[0];
		int i, j;
		for (i = j = 1; i < n; ++i) {
			if (A[i] != val) val = A[i], A[j++] = A[i];
			else N--;
		}
		return N;
	}
};

void main()
{
	int A[] = { 1, 1, 2, 2, 2, 3, 4, 5, 6, 6, 7, 8, 8, 8, 9, 10 };
	copy(cbegin(A), cend(A), ostream_iterator<int>(cout, " "));
	cout << endl;
	Solution solution;
	cout << solution.removeDuplicates(A, sizeof(A) / sizeof(int)) << endl;
	copy(cbegin(A), cend(A), ostream_iterator<int>(cout, " "));
	cout << endl;
}
