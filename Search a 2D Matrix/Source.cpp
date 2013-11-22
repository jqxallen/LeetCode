#include <vector>
using namespace::std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		int row = matrix.size();
		if (!row) return 0;
		int col = matrix[0].size();
		if (!col) return 0;
		int i = 0, j = col - 1;
		while (i < row && j > -1) {
			if (matrix[i][j] > target) j--;
			else if (matrix[i][j] < target) i++;
			else return 1;
		}
		return 0;
	}
};