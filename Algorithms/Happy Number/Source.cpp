/*
 * Author: Qiang Jia
 * Date: Apr 23, 2015
 * Link: https://leetcode.com/problems/happy-number/
 * Description:
 *		Write an algorithm to determine if a number is "happy".
 *		A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *		Example: 19 is a happy number
 *			1^2 + 9^2 = 82
 *			8^2 + 2^2 = 68
 *			6^2 + 8^2 = 100
 *			1^2 + 0^2 + 02 = 1
 */

#include <iostream>
#include <set>
using namespace::std;

class Solution {
public:
	bool isHappy(int n) {
		if (n < 1)
			return 0;
		set<int> s;
		int t;
		while (s.find(t) == s.cend()) {
			s.insert(t);
			t = 0;
			while (n) {
				t += int(pow(n % 10 * 1.0, 2));
				n /= 10;
			}
			if (t == 1)
				return 1;
			n = t;
		}
		return 0;
	}
};

void main()
{
	Solution solution;
	cout << solution.isHappy(19) << endl;
}
