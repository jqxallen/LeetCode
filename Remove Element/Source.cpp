class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!n) return 0;
		int i, j = n - 1, N = n;
		for (i = 0; i <= j; ++i)
			if (A[i] == elem)
				A[i--] = A[j--], N--;
		return N;
	}
};