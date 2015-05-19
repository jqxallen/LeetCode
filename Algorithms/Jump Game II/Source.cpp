/*
 * Author: Qiang Jia
 * Date: Apr 15, 2015
 * Link: https://leetcode.com/problems/jump-game-ii/
 * Description:
 *      Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *      Each element in the array represents your maximum jump length at that position.
 *      Your goal is to reach the last index in the minimum number of jumps.
 *      For example:
 *          Given array A = [2,3,1,1,4]
 *          The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */

#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1)
			return 0;
		int i = 0, j = 1, step = 0, max;
		while (i < nums.size() - 1 && i + nums[i] < nums.size() - 1) {
			for (max = j; j <= i + nums[i]; ++j)
			if (j + nums[j] >= max + nums[max])
				max = j;
			i = max;
			++step;
		}
		return ++step;
	}
};

void main()
{
	int arr[] = { 2, 3, 1, 1, 4 };
	vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
	Solution solution;
	cout << solution.jump(nums) << endl;
}
