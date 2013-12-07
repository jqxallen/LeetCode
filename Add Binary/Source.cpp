#include <iostream>
#include <string>
using namespace::std;

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.empty()) return b;
		if (b.empty()) return a;
		string s;
		int i, j, c, carry = 0;
		for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; --i, --j) {
			c = (int)(a[i] - '0') + (int)(b[j] - '0') + carry;
			carry = c / 2;
			c %= 2;
			s = to_string(c) + s;
		}
		for (; i >= 0; --i) {
			c = (int)(a[i] - '0') + carry;
			carry = c / 2;
			c %= 2;
			s = to_string(c) + s;
		}
		for (; j >= 0; --j) {
			c = (int)(b[j] - '0') + carry;
			carry = c / 2;
			c %= 2;
			s = to_string(c) + s;
		}
		if (carry) s = to_string(carry) + s;
		return s;
	}
};

void main()
{
	Solution solution;
	cout << solution.addBinary("11", "1") << endl;

	system("pause");
}