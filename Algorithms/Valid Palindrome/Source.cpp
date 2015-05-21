/*
 * Author: Qiang Jia
 * Date: Nov 1, 2013
 * Link: https://leetcode.com/problems/valid-palindrome/
 * Description:
 *		Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *		For example,
 *			"A man, a plan, a canal: Panama" is a palindrome.
 *			"race a car" is not a palindrome.
 *		Note:
 *			Have you consider that the string might be empty? This is a good question to ask during an interview.
 *			For the purpose of this problem, we define empty string as valid palindrome.
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace::std;

class Solution {
public:
	bool isPalindrome(string s) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		s.erase(remove_if(s.begin(), s.end(), [](char c) {
			return !isalnum(c);
		}), s.end());
		return s == string(s.rbegin(), s.rend());
	}
};

void main()
{
	string s = "A man, a plan, a canal: Panama";
	Solution solution;
	cout << solution.isPalindrome(s) << endl;
}
