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

	system("pause");
}