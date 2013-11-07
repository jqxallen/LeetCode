#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace::std;

class Solution {
public:
	void generate(vector<string> &coll, int l, int r, string s) {
		if (!l && !r) {
			coll.push_back(s);
		} else {
			if (l) generate(coll, l - 1, r, s + '(');
			if (r > l) generate(coll, l, r - 1, s + ')');
		}
	}
    vector<string> generateParenthesis(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> coll;
		this->generate(coll, n, n, "");
		return coll;
    }
};

void main()
{
	Solution solution;
	vector<string> coll = solution.generateParenthesis(3);

	copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));

	system("pause");
}