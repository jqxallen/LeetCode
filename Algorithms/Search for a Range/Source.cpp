/*
 * Author: Qiang Jia
 * Date: Dec 11, 2013
 * Link: https://leetcode.com/problems/search-for-a-range/
 * Description:
 *		Given a sorted array of integers, find the starting and ending position of a given target value.
 *		Your algorithm's runtime complexity must be in the order of O(log n).
 *		If the target is not found in the array, return [-1, -1].
 *		For example,
 *			Given [5, 7, 7, 8, 8, 10] and target value 8,
 *			return [3, 4].
 */

#include <iostream>
#include <vector>
#include <iterator>
using namespace::std;

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> idx = { -1, -1 };
		if (!n) return idx;
		int i = 0, j = n - 1;
		while (i < j) {
			int k = (i + j) / 2;
			if (A[k] < target) i = k + 1;
			else j = k;
		}
		if (A[i] == target) idx[0] = i;
		else return idx;
		j = n;
		while (i < j) {
			int k = (i + j) / 2;
			if (A[k] > target) j = k;
			else i = k + 1;
		}
		idx[1] = i - 1;
		return idx;
	}
};

void main()
{
	int A[] = { 5, 7, 7, 8, 8, 10 };
	int n = sizeof(A) / sizeof(int);
	int target = 8;
	Solution solution;
	vector<int> idx = solution.searchRange(A, n, target);
	copy(idx.cbegin(), idx.cend(), ostream_iterator<int>(cout, "\n"));
}
