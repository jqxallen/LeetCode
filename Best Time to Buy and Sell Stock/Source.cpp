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