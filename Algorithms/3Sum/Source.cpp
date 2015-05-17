/*
 * Author: Qiang Jia
 * Date: Nov 1, 2013
 * Link: https://leetcode.com/problems/3sum/
 * Description:
 *		Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *		Note:
 *			Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
 *			The solution set must not contain duplicate triplets.
 *			For example, given array S = {-1 0 1 2 -1 -4},
 *			A solution set is:
 *				(-1, 0, 1)
 *				(-1, -1, 2)
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace::std;

class Solution {
public:
	void find_numbers(const vector<int> &num, int N, int begin, int end, vector<vector<int>> &colls, vector<int> coll) {
		for (int i = begin; i < end; ++i) {
			if (i > begin && num[i] == num[i - 1]) continue;
			coll.push_back(num[i]);
			int sum = accumulate(coll.cbegin(), coll.cend(), 0);
			if (sum > 0) return;
			if (N == 1) {
				if (sum == 0) {
					colls.push_back(coll);
					return;
				}
				coll.pop_back();
			}
			else {
				find_numbers(num, N - 1, i + 1, end + 1, colls, coll);
				coll.pop_back();
			}
		}
	}
	vector<vector<int> > threeSum(vector<int> &num) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		sort(num.begin(), num.end());
		vector<vector<int>> colls;
		vector<int> coll;
		int N = 3;
		find_numbers(num, N, 0, num.size() - N + 1, colls, coll);
		return colls;
	}
};

void main()
{
	int arr[] = { -1, 0, 1, 2, -1, -4 };
	vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
	Solution solution;
	for (const auto &coll : solution.threeSum(num)) {
		copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}
