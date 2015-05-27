/*
 * Author: Qiang Jia
 * Date: May 27, 2015
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 * Description:
 *		Say you have an array for which the ith element is the price of a given stock on day i.
 *		Design an algorithm to find the maximum profit. You may complete at most k transactions.
 *		Note:
 *			You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int profit = 0;
		for (int i = 1; i < prices.size(); ++i)
			profit += max(prices[i] - prices[i - 1], 0);
		return profit;
	}
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty())
			return 0;
		int n = prices.size();
		if (k >= n)
			return maxProfit(prices);
		vector<int> global(k + 1), local(k + 1);
		for (int i = 0; i < n - 1; ++i) {
			int diff = prices[i + 1] - prices[i];
			for (int j = k; j > 0; --j) {
				local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
				global[j] = max(local[j], global[j]);
			}
		}
		return global[k];
	}
};
