/*
 * Author: Qiang Jia
 * Date: Jun 20, 2015
 * Link: https://leetcode.com/problems/contains-duplicate-iii/
 * Description:
 *      Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
 */

#include <iostream>
#include <vector>
#include <set>
using namespace::std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (nums.size() < 2 || k < 1 || t < 0)
			return false;
		set<long long> cache;
		for (int i = 0; i < nums.size(); ++i) {
			if (i > k)
				cache.erase(nums[i - k - 1]);
			for (auto it = cache.lower_bound((long long)nums[i] - t); it != cache.upper_bound((long long)nums[i] + t); ++it)
				return true;
			cache.insert(nums[i]);
		}
		return false;
	}
};

void main()
{
	int arr[] = { 0, 2147483647 };
	vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
	Solution solution;
	cout << solution.containsNearbyAlmostDuplicate(nums, 1, 2147483647) << endl;
}
