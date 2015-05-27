/*
 * Author: Qiang Jia
 * Date: May 27, 2015
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * Description:
 *		Say you have an array for which the ith element is the price of a given stock on day i.
 *		Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *		Note:
 *			You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		vector<int> l(prices.size());
		vector<int> r(prices.size());
		int n = prices.size(), buy = prices[0], sell = prices[n - 1];
		for (int i = 1; i < n; ++i) {
			buy = min(prices[i], buy);
			l[i] = max(prices[i] - buy, l[i - 1]);
			sell = max(prices[n - i - 1], sell);
			r[n - i - 1] = max(sell - prices[n - i - 1], r[n - i]);
		}
		int profit = 0;
		for (int i = 0; i < n; ++i)
			profit = max(l[i] + r[i], profit);
		return profit;
	}
};
