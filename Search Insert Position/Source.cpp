class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!n) return 0;
		int i = 0, j = n, k;
		while (i <= j) {
			k = (i + j) / 2;
			if (k && A[k - 1] < target && target < A[k]) return k;
			else if (target < A[k]) if (k == j) return k; else j = k;
			else if (target > A[k]) if (k == i) return k + 1; else i = k;
			else return k;
		}
		return -1;
	}
};