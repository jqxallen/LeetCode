class Solution {
public:
	int removeDuplicates(int A[], int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!n) return 0;
		int i, j, val = A[0], counter = 1, N = n;
		for (i = j = 1; i < n; ++i) {
			if (A[i] != val) val = A[i], counter = 1, A[j++] = A[i];
			else if (counter == 2) N--;
			else counter++, A[j++] = A[i];
		}
		return N;
	}
};