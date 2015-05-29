/*
 * Author: Qiang Jia
 * Date: May 29, 2015
 * Link: https://leetcode.com/problems/combination-sum-iii/
 * Description:
 *		Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 *		Ensure that numbers within the set are sorted in ascending order.
 *		Example 1:
 *			Input: k = 3, n = 7
 *			Output:
 *				[[1,2,4]]
 *		Example 2:
 *			Input: k = 3, n = 9
 *			Output:
 *				[[1,2,6], [1,3,5], [2,3,4]]
 */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace::std;

class Solution {
public:
	void backtrack(int k, int n, int p) {
		if (k == 0 && n == 0) {
			results.push_back(vector<int>(stack.cbegin(), stack.cend()));
			return;
		}
		if (k < 0 || n < p)
			return;
		for (int i = p; i <= 9; ++i) {
			stack.push_back(i);
			backtrack(k - 1, n - i, i + 1);
			stack.pop_back();
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		backtrack(k, n, 1);
		return results;
	}
private:
	deque<int> stack;
	vector<vector<int>> results;
};

void main()
{
	int k = 3, n = 9;
	Solution solution;
	vector<vector<int>> results = solution.combinationSum3(k, n);
	for (auto it = results.cbegin(); it != results.cend(); ++it) {
		copy(it->cbegin(), it->cend(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}
