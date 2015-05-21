/*
 * Author: Qiang Jia
 * Date: Apr 14, 2015
 * Link: https://leetcode.com/problems/plus-one/
 * Description:
 *      Given a non-negative number represented as an array of digits, plus one to the number.
 *      The digits are stored such that the most significant digit is at the head of the list.
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace::std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		vector<int> v(digits);
		int carry = 1;
		for_each(v.rbegin(), v.rend(), [&](int &i) {
			int tmp = i + carry;
			i = tmp % 10;
			carry = tmp / 10;
		});
		if (carry)
			v.insert(v.begin(), carry);
		return v;
	}
};

void main()
{
	int arr[] = { 9, 9, 9 };
	vector<int> digits(arr, arr + sizeof(arr) / sizeof(int));
	Solution solution;
	vector<int> v = solution.plusOne(digits);
	copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, "\n"));
}
