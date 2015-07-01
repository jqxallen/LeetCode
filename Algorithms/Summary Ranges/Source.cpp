/*
 * Author: Qiang Jia
 * Date: Jul 1, 2015
 * Link: https://leetcode.com/problems/summary-ranges/
 * Description:
 *      Given a sorted integer array without duplicates, return the summary of its ranges.
 *      For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
using namespace::std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> results;
		int diff = nums.size() > 1 && nums[1] - nums[0] < 0 ? -1 : 1;
		int i, j = INT_MIN, n = nums.size();
		for (i = 0; i < n; ++i) {
			if (j == INT_MIN)
				j = i;
			if (i + 1 < n) {
				if (nums[i + 1] - nums[i] != diff) {
					if (i == j)
						results.push_back(convert(nums[j]));
					else
						results.push_back(convert(nums[j], nums[i]));
					j = INT_MIN;
				}
			}
		}
		if (i - 1 == j)
			results.push_back(convert(nums[j]));
		else if (j != INT_MIN)
			results.push_back(convert(nums[j], nums[i - 1]));
		return results;
	}
private:
	string convert(const int n) {
		stringstream ss;
		ss << n;
		return ss.str();
	}
	string convert(const int n1, const int n2) {
		return convert(n1) + "->" + convert(n2);
	}
};

void main()
{
	vector<int> nums = { 0, 1, 2, 4, 5, 7 };
	Solution solution;
	vector<string> results = solution.summaryRanges(nums);
	copy(results.cbegin(), results.cend(), ostream_iterator<string>(cout, "\n"));
}
