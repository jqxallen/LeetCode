/*
 * Author: Qiang Jia
 * Date: Nov 13, 2013
 * Link: https://leetcode.com/problems/4sum/
 * Description:
 *		Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *		Note:
 *			Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a <= b <= c <= d)
 *			The solution set must not contain duplicate quadruplets.
 *			For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *			A solution set is:
 *				(-1,  0, 0, 1)
 *				(-2, -1, 1, 2)
 *				(-2,  0, 0, 2)
 */

#include <vector>
#include <set>
#include <numeric>
#include <iterator>
#include <algorithm>
using namespace::std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<vector<int>> colls;
		int size = num.size();
		if (size < 4) return colls;
		sort(num.begin(), num.end());
		set<vector<int>> temp_colls;
		for (int i = 0; i < size; ++i) {
			for (int j = i + 1; j < size; ++j) {
				int begin = j + 1, end = size - 1;
				while (begin < end) {
					int sum = num[i] + num[j] + num[begin] + num[end];
					if (sum > target) end--;
					else if (sum < target) begin++;
					else {
						vector<int> coll = { num[i], num[j], num[begin], num[end] };
						temp_colls.insert(coll);
						begin++;
						end--;
					}
				}
			}
		}
		copy(temp_colls.cbegin(), temp_colls.cend(), back_inserter<vector<vector<int>>>(colls));
		return colls;
	}
};
