#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> v{1};
		while (rowIndex--) {
			vector<int> t{1};
			for (int i = 0; i < v.size() - 1; ++i)
				t.push_back(v[i] + v[i + 1]);
			t.push_back(1);
			v = t;
		}
		return v;
	}
};
