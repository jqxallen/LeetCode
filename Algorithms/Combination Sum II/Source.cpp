/*
 * Author: Qiang Jia
 * Date: May 29, 2015
 * Link: https://leetcode.com/problems/combination-sum-ii/
 * Description:
 *		Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *		Each number in C may only be used once in the combination.
 *		Note:
 *			1. All numbers (including target) will be positive integers.
 *			2. Elements in a combination (a1, a2, ... , ak) must be in non-descending order. (ie, a1 <= a2 <= ... <= ak).
 *			3. The solution set must not contain duplicate combinations.
 *		For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 *			A solution set is:
 *				[1, 7]
 *				[1, 2, 5]
 *				[2, 6]
 *				[1, 1, 6]
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
		stack.push_back(candidates[k]);
		backtrack(candidates, val - candidates[k], k + 1);
		stack.pop_back();
		while (k + 1 < candidates.size() && candidates[k + 1] == candidates[k])
			++k;
		backtrack(candidates, val, k + 1);
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
	int arr[] = { 10, 1, 2, 7, 6, 1, 5 };
	vector<int> candidates(arr, arr + sizeof(arr) / sizeof(int));
	int target = 8;
	Solution solution;
	vector<vector<int>> results = solution.combinationSum2(candidates, target);
	for (auto it = results.cbegin(); it != results.cend(); ++it) {
		copy(it->cbegin(), it->cend(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}
