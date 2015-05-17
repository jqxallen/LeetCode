/*
 * Author: Qiang Jia
 * Date: Apr 17, 2015
 * Link: https://leetcode.com/problems/3sum-closest/
 * Description:
 *		Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *		For example, given array S = {-1 2 1 -4}, and target = 1.
 *		The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int i, j, k, sum, min = num[0] + num[1] + num[num.size() - 1];
		for (i = 0; i < num.size() - 2; ++i) {
			j = i + 1, k = num.size() - 1;
			while (j < k) {
				sum = num[i] + num[j] + num[k];
				if (sum == target) return sum;
				if (sum > target) --k;
				else ++j;
				min = (abs(sum - target) < abs(min - target)) ? sum : min;
			}
		}
		return min;
	}
};

void main()
{
	int arr1[] = { -1, 2, 1, -4 };
	vector<int> num1(arr1, arr1 + sizeof(arr1) / sizeof(int));
	int arr2[] = { -3, -2, -5, 3, -4 };
	vector<int> num2(arr2, arr2 + sizeof(arr2) / sizeof(int));
	int target1 = 1;
	int target2 = -1;
	Solution solution;
	cout << solution.threeSumClosest(num1, target1) << endl;
	cout << solution.threeSumClosest(num2, target2) << endl;
}
