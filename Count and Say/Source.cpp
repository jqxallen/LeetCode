#include <iostream>
#include <string>
using namespace::std;

class Solution {
public:
	string countAndSay(int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (n < 1) return "";
		string s = "1";
		while (--n) {
			int num;
			char c;
			string tmp;
			for (int i = 0; i < s.size(); ++i)
				if (i == 0) num = 1, c = s[i];
				else if (s[i] == c) num++;
				else tmp += to_string(num) + c, num = 1, c = s[i];
			tmp += to_string(num) + c;
			s = tmp;
		}
		return s;
	}
};

void main()
{
	Solution solution;
	cout << solution.countAndSay(6) << endl;

	system("pause");
}