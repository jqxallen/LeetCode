/*
 * Author: Qiang Jia
 * Date: Jul 4, 2015
 * Link: https://leetcode.com/problems/majority-element-ii/
 * Description:
 *      Given an integer array of size n, find all elements that appear more than [n/3] times. The algorithm should run in linear time and in O(1) space.
 *      Hint:
 *			1. How many majority elements could it possibly have?
 */

#include <iostream>
#include <vector>
#include <iterator>
using namespace::std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int v1, v2, c1 = 0, c2 = 0;
		for (int i : nums) {
			if (!c1) v1 = i;
			else if (!c2) v2 = i;
			if (i == v1) ++c1;
			else if (i == v2) ++c2;
			else {
				if (c1) --c1;
				if (c2) --c2;
			}
		}
		vector<int> results;
		c1 = c2 = 0;
		for (int i : nums) {
			if (i == v1) ++c1;
			else if (i == v2) ++c2;
		}
		if (c1 > nums.size() / 3) results.push_back(v1);
		if (c2 > nums.size() / 3) results.push_back(v2);
		return results;
	}
};

void main()
{
	vector<int> nums = { 1, 1, 1, 1, 2, 2, 2, 2, 3 };
	Solution solution;
	vector<int> results = solution.majorityElement(nums);
	copy(results.cbegin(), results.cend(), ostream_iterator<int>(cout, "\n"));
}