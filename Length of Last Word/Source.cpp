#include <iostream>
#include <string>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int i, j = -1;
		for (i = s.size() - 1; i >= 0; --i) {
			if (j != -1 && s[i] == ' ')
				break;
			if (j == -1 && s[i] != ' ')
				j = i;
		}
		return j - i;
	}
};

int main()
{
	Solution solution;
	cout << (solution.lengthOfLastWord("") == 0) << endl;
	cout << (solution.lengthOfLastWord("  ") == 0) << endl;
	cout << (solution.lengthOfLastWord(" word ") == 4) << endl;
	cout << (solution.lengthOfLastWord(" word  ") == 4) << endl;
	cout << (solution.lengthOfLastWord("hello world") == 5) << endl;
}
