/*
 * Author: Qiang Jia
 * Date: Apr 15, 2015
 * Link: https://leetcode.com/problems/jump-game/
 * Description:
 *      Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *      Each element in the array represents your maximum jump length at that position.
 *      Determine if you are able to reach the last index.
 *      For example:
 *          A = [2,3,1,1,4], return true.
 *          A = [3,2,1,0,4], return false.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int jump = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (i > jump) return 0;
			jump = max(jump, i + nums[i]);
		}
		return 1;
	}
};

void main()
{
	int arr[] = { 2, 3, 1, 1, 4 };
	vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
	Solution solution;
	cout << (solution.canJump(nums) == 1) << endl;
}
