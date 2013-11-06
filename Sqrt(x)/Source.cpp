#include <iostream>
#include <algorithm>
using namespace::std;

class Solution {
public:
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		double b = 10000;
		while (abs(x - b * b) > 1) b = 0.5 * (b + x / b);
		return b;
    }
};

void main()
{
	Solution solution;
	cout << solution.sqrt(6) << endl;

	system("pause");
}