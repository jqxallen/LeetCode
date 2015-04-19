#include <iostream>
using namespace::std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return 0;
		int p = x, q = 0;
		while (p >= 10) {
			q *= 10;
			q += p % 10;
			p /= 10;
		}
		return q == x / 10 && p == x % 10;
	}
};

int main()
{
	Solution solution;
	cout << solution.isPalindrome(0) << endl;
	cout << !solution.isPalindrome(12) << endl;
	cout << solution.isPalindrome(121) << endl;
	cout << !solution.isPalindrome(-121) << endl;
	cout << solution.isPalindrome(1001) << endl;
	cout << solution.isPalindrome(12021) << endl;
}
