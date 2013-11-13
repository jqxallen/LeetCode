#include <iostream>
#include <iterator>
using namespace::std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!n) return 0;
		int N = n, val = A[0];
		int i, j;
		for (i = j = 1; i < n; ++i) {
			if (A[i] != val) val = A[i], A[j++] = A[i];
			else N--;
		}
		return N;
	}
};

void main()
{
	int A[] = {1,1,2,2,2,3,4,5,6,6,7,8,8,8,9,10};

	copy(cbegin(A), cend(A), ostream_iterator<int>(cout, " "));
	cout << endl;

	Solution solution;
	cout << solution.removeDuplicates(A, sizeof(A) / sizeof(int)) << endl;

	copy(cbegin(A), cend(A), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
}