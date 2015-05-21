/*
 * Author: Qiang Jia
 * Date: Apr 19, 2015
 * Link: https://leetcode.com/problems/length-of-last-word/
 * Description:
 *		Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *		If the last word does not exist, return 0.
 *		Note:
 *			A word is defined as a character sequence consists of non-space characters only.
 *		For example,
 *			Given s = "Hello World",
 *			return 5.
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int i, j = -1;
		for (i = s.size() - 1; i >= 0; --i) {
			if (j != -1 && s[i] == ' ')
				break;
			if (j == -1 && s[i] != ' ')
				j = i;
		}
		return j - i;
	}
};

void main()
{
	Solution solution;
	cout << (solution.lengthOfLastWord("") == 0) << endl;
	cout << (solution.lengthOfLastWord("  ") == 0) << endl;
	cout << (solution.lengthOfLastWord(" word ") == 4) << endl;
	cout << (solution.lengthOfLastWord(" word  ") == 4) << endl;
	cout << (solution.lengthOfLastWord("hello world") == 5) << endl;
}
