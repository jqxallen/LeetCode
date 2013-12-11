#include <iostream>
#include <vector>
#include <iterator>
using namespace::std;

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> idx = {-1, -1};
		if (!n) return idx;
		int i = 0, j = n - 1;
		while (i < j) {
			int k = (i + j) / 2;
			if (A[k] < target) i = k + 1;
			else j = k;
		}
		if (A[i] == target) idx[0] = i;
		else return idx;
		j = n;
		while (i < j) {
			int k = (i + j) / 2;
			if (A[k] > target) j = k;
			else i = k + 1;
		}
		idx[1] = i - 1;
		return idx;
	}
};

void main()
{
	int A[] = {5, 7, 7, 8, 8, 10};
	int n = sizeof(A) / sizeof(int);
	int target = 8;

	Solution solution;
	vector<int> idx = solution.searchRange(A, n, target);
	copy(idx.cbegin(), idx.cend(), ostream_iterator<int>(cout, "\n"));

	system("pause");
}