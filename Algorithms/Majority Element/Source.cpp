/*
 * Author: Qiang Jia
 * Date: Apr 19, 2015
 * Link: https://leetcode.com/problems/majority-element/
 * Description:
 *		Given an array of size n, find the majority element. The majority element is the element that appears more than ‚å? n/2 ‚å? times.
 *		You may assume that the array is non-empty and the majority element always exist in the array.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int majorityElement(vector<int> &num) {
		sort(num.begin(), num.end());
		return num[num.size() / 2];
	}
};
