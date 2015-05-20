/*
 * Author: Qiang Jia
 * Date: Nov 5, 2013
 * Link: https://leetcode.com/problems/merge-sorted-array/
 * Description:
 *		Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *		Note:
 *			You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

#include <iostream>
using namespace::std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (i >= 0 && j >= 0) {
			if (A[i] > B[j]) A[k--] = A[i--];
			else A[k--] = B[j--];
		}
		while (i >= 0) A[k--] = A[i--];
		while (j >= 0) A[k--] = B[j--];
	}
};
