#include <iostream>
using namespace::std;

class Solution {
public:
	int reverse(int x) {
		int sign = x >= 0 ? 1 : -1;
		x = abs(x);
		int y = 0, t;
		while (x > 0) {
			t = x % 10;
			if (y > (INT_MAX - t) / 10)
				return 0;
			y = y * 10 + t;
			x /= 10;
		}
		return sign * y;
	}
};

int main()
{
	Solution solution;
	cout << (solution.reverse(0) == 0) << endl;
	cout << (solution.reverse(123) == 321) << endl;
	cout << (solution.reverse(-123) == -321) << endl;
	cout << (solution.reverse(1020) == 201) << endl;
	cout << (solution.reverse(INT_MAX) == 0) << endl;
	cout << (solution.reverse(INT_MIN) == 0) << endl;
}
