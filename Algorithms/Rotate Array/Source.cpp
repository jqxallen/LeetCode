/*
 * Author: Qiang Jia
 * Date: Mar 18, 2015
 * Link: https://leetcode.com/problems/rotate-array/
 * Description:
 *      Rotate an array of n elements to the right by k steps.
 *      For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 *      Note:
 *          Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 *      Hint:
 *          Could you do it in-place with O(1) extra space?
 *          Related problem: Reverse Words in a String II (https://leetcode.com/problems/reverse-words-in-a-string-ii/)
 */

#include <iostream>
using namespace::std;

class Solution {
public:
	void _rotate_(int nums[], int n, int k, int s) {
		int i = s, num = nums[i], tmp;
		do {
			tmp = nums[(i + k) % n];
			nums[(i + k) % n] = num;
			i = (i + k) % n;
			num = tmp;
		} while (i != s);
	}
	void rotate(int nums[], int n, int k) {
		if (n < 2 || k < 1 || k % n == 0) return;
		k = k % n;
		int min = k < (n - k) ? k : n - k;
		if (n % 2 == 0 && n % min == 0) {
			for (int i = 0; i < min; ++i)
				_rotate_(nums, n, k, i);
		}
		else {
			_rotate_(nums, n, k, 0);
		}
	}
};

void main() {
	int n = 6, k = 3;
	int nums[] = { 1, 2, 3, 4, 5, 6 };
	Solution solution;
	for (auto i : nums) cout << i << " "; cout << endl;
	solution.rotate(nums, n, k);
	for (auto i : nums) cout << i << " "; cout << endl;
}
