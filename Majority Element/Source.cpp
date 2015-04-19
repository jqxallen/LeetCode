#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int majorityElement(vector<int> &num) {
		sort(num.begin(), num.end());
		return num[num.size() / 2];
	}
};
