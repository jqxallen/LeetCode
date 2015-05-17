/*
 * Author: Qiang Jia
 * Date: Nov 14, 2013
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Description:
 *		Say you have an array for which the ith element is the price of a given stock on day i.
 *		If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */

#include <vector>
using namespace::std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		int idx = 0, profit = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] < prices[idx]) idx = i;
			else if (prices[i] - prices[idx] > profit) profit = prices[i] - prices[idx];
		}
		return profit;
	}
};
