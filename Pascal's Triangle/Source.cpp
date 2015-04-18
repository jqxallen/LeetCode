#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int>> v;
		if (numRows < 1)
			return v;
		v.push_back(vector<int>(1, 1));
		while (--numRows) {
			vector<int> t(1, 1);
			for (int i = 0; i < v.back().size() - 1; ++i)
				t.push_back(v.back()[i] + v.back()[i + 1]);
			t.push_back(1);
			v.push_back(t);
		}
		return v;
	}
};
