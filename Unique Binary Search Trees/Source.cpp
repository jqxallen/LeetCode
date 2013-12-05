#include <iostream>
using namespace::std;

class Solution {
public:
	int numTrees(int begin, int end) {
		if (begin >= end) return 1;
		int count = 0;
		for (int i = begin; i <= end; ++i)
			count += this->numTrees(begin, i - 1) * this->numTrees(i + 1, end);
		return count;
	}
	int numTrees(int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		return this->numTrees(1, n);
	}
};

void main()
{
	Solution solution;
	cout << solution.numTrees(3) << endl;

	system("pause");
}