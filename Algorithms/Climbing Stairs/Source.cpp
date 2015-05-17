/*
 * Author: Qiang Jia
 * Date: Apr 19, 2015
 * Link: https://leetcode.com/problems/climbing-stairs/
 * Description:
 *		You are climbing a stair case. It takes n steps to reach to the top.
 *		Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

class Solution {
public:
	int climbStairs(int n) {
		if (n < 3) return n;
		n -= 2;
		int a = 1, b = 2, t;
		while (n--) {
			t = a + b;
			a = b;
			b = t;
		}
		return b;
	}
};
