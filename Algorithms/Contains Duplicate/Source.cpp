/*
 * Author: Qiang Jia
 * Date: May 31, 2015
 * Link: https://leetcode.com/problems/contains-duplicate/
 * Description:
 *      Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] == nums[i - 1])
				return true;
		}
		return false;
	}
};
