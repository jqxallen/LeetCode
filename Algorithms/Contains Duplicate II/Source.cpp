/*
 * Author: Qiang Jia
 * Date: Jun 1, 2015
 * Link: https://leetcode.com/problems/contains-duplicate-ii/
 * Description:
 *      Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace::std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> cache;
		for (int i = 0; i < nums.size(); ++i) {
			auto pos = cache.find(nums[i]);
			if (pos == cache.end())
				cache.insert({ nums[i], i });
			else if (i - pos->second > k)
				pos->second = i;
			else
				return true;
		}
		return false;
	}
};
