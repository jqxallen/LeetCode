/*
 * Author: Qiang Jia
 * Date: Apr 14, 2015
 * Link: https://leetcode.com/problems/find-peak-element/
 * Description:
 *      A peak element is an element that is greater than its neighbors.
 *      Given an input array where num[i] != num[i+1], find a peak element and return its index.
 *      The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 *      You may imagine that num[-1] = num[n] = INT_MIN.
 *      For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 *      Note:
 *          Your solution should be in logarithmic complexity.
 */

#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
	int _find_local_peak_(const vector<int> &num, int start, int end, int size) {
		int middle = (start + end) / 2;
		if ((middle == 0 || num[middle] > num[middle - 1]) && (middle == size - 1 || num[middle] > num[middle + 1]))
			return middle;
		else if (num[middle] > num[middle + 1])
			return this->_find_local_peak_(num, start, middle, size);
		return this->_find_local_peak_(num, middle + 1, end, size);
	}
	int findPeakElement(const vector<int> &num) {
		return this->_find_local_peak_(num, 0, num.size() - 1, num.size());
	}
};

void main()
{
	int arr[] = { 1, 2, 3, 1 };
	vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
	Solution solution;
	cout << solution.findPeakElement(num) << endl;
}
