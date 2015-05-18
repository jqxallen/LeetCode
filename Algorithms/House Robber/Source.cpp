/*
 * Author: Qiang Jia
 * Date: Apr 13, 2015
 * Link: https://leetcode.com/problems/house-robber/
 * Description:
 *      You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *      Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int rob(vector<int> &num) {
		if (num.empty())
			return 0;
		int foo = num[0], bar = 0, tmp;
		for (int i = 1; i < num.size(); ++i) {
			tmp = foo;
			foo = max(foo, bar + num[i]);
			bar = tmp;
		}
		return max(foo, bar);
	}
};

void main() {
	int arr[] = { 2, 7, 1, 13, 5, 11, 19, 3 };
	vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
	Solution solution;
	cout << solution.rob(num) << endl;
}
