#include <algorithm>
using namespace::std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (m < 1 || n < 1) return 0;
		if (m > n) swap(m, n);
		n += m - 2, m--;
		long long val = 1;
		for (int i = 1; i <= m; ++i)
			val = val * (n - i + 1) / i;
		return val;
	}
};