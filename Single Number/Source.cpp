#include <vector>
using namespace::std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		vector<int> coll(A, A + n);
        int val = 0;
		for (int i: coll)
			val ^= i;
		return val;
    }
};