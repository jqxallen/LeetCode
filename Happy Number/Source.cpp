#include <iostream>
#include <set>
using namespace::std;

class Solution {
public:
	bool isHappy(int n) {
		if (n < 1)
			return 0;
		set<int> s;
		int t;
		while (s.find(t) == s.cend()) {
			s.insert(t);
			t = 0;
			while (n) {
				t += int(pow(n % 10 * 1.0, 2));
				n /= 10;
			}
			if (t == 1)
				return 1;
			n = t;
		}
		return 0;
	}
};

int main()
{
	Solution solution;
	cout << solution.isHappy(19) << endl;
}
