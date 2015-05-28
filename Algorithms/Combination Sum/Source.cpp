/*
 * Author: Qiang Jia
 * Date: May 28, 2015
 * Link: https://leetcode.com/problems/combination-sum/
 * Description:
 *		Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *		The same repeated number may be chosen from C unlimited number of times.
 *		Note:
 *			1. All numbers (including target) will be positive integers.
 *			2. Elements in a combination (a1, a2, ... , ak) must be in non-descending order. (ie, a1 <= a2 <= ... <= ak).
 *			3. The solution set must not contain duplicate combinations.
 *		For example, given candidate set 2,3,6,7 and target 7,
 *			A solution set is:
 *				[7]
 *				[2, 2, 3]
 */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace::std;

class Solution {
public:
	void backtrack(const vector<int> &candidates, int val, int k) {
		if (val == 0) {
			results.push_back(vector<int>(stack.cbegin(), stack.cend()));
			return;
		}
		if (k >= candidates.size() || val < candidates[k])
			return;
		int n = val / candidates[k];
		for (int i = 1; i <= n; ++i) {
			stack.push_back(candidates[k]);
			backtrack(candidates, val - i * candidates[k], k + 1);
		}
		while (n--) {
			stack.pop_back();
		}
		backtrack(candidates, val, k + 1);
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		backtrack(candidates, target, 0);
		return results;
	}
private:
	deque<int> stack;
	vector<vector<int>> results;
};

void main()
{
	int arr[] = { 2, 3, 5 };
	vector<int> candidates(arr, arr + sizeof(arr) / sizeof(int));
	int target = 7;
	Solution solution;
	vector<vector<int>> results = solution.combinationSum(candidates, target);
	for (auto it = results.cbegin(); it != results.cend(); ++it) {
		copy(it->cbegin(), it->cend(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}
