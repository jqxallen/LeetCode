#include <vector>
#include <set>
#include <numeric>
#include <iterator>
#include <algorithm>
using namespace::std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<vector<int>> colls;
		int size = num.size();
		if (size < 4) return colls;

		sort(num.begin(), num.end());
		set<vector<int>> temp_colls;
		for (int i = 0; i < size; ++i) {
			for (int j = i + 1; j < size; ++j) {
				int begin = j + 1, end = size - 1;
				while (begin < end) {
					int sum = num[i] + num[j] + num[begin] + num[end];
					if (sum > target) end--;
					else if (sum < target) begin++;
					else {
						vector<int> coll = {num[i], num[j], num[begin], num[end]};
						temp_colls.insert(coll);
						begin++;
						end--;
					}
				}
			}
		}

		copy(temp_colls.cbegin(), temp_colls.cend(), back_inserter<vector<vector<int>>>(colls));
		return colls;
	}
};