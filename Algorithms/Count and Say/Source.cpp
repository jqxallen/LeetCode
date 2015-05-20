/*
 * Author: Qiang Jia
 * Date: Nov 13, 2013
 * Link: https://leetcode.com/problems/count-and-say/
 * Description:
 *		The count-and-say sequence is the sequence of integers beginning as follows:
 *		1, 11, 21, 1211, 111221, ...
 *		1 is read off as "one 1" or 11.
 *		11 is read off as "two 1s" or 21.
 *		21 is read off as "one 2, then one 1" or 1211.
 *		Given an integer n, generate the nth sequence.
 *		Note:
 *			The sequence of integers will be represented as a string.
 */

#include <iostream>
#include <string>
using namespace::std;

class Solution {
public:
	string countAndSay(int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (n < 1) return "";
		string s = "1";
		while (--n) {
			int num;
			char c;
			string tmp;
			for (int i = 0; i < s.size(); ++i)
			if (i == 0) num = 1, c = s[i];
			else if (s[i] == c) num++;
			else tmp += to_string(num) + c, num = 1, c = s[i];
			tmp += to_string(num) + c;
			s = tmp;
		}
		return s;
	}
};

void main()
{
	Solution solution;
	cout << solution.countAndSay(6) << endl;
}
