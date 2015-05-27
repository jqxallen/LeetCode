/*
 * Author: Qiang Jia
 * Date: May 27, 2015
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * Description:
 *		Say you have an array for which the ith element is the price of a given stock on day i.
 *		Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0, total = 0, idx = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] < prices[i - 1]) {
				total += profit;
				profit = 0;
				idx = i;
			}
			else if (prices[i] > prices[idx]) {
				profit = prices[i] - prices[idx];
			}
		}
		return total + profit;
	}
};
