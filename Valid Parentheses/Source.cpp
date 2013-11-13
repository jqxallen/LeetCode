#include <stack>
#include <string>
using namespace::std;

class Solution {
public:
	bool isValid(string s) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!s.size()) return 1;
		stack<char> stk;
		for (int i = 0; i < s.size(); ++i) {
			if (stk.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}'))
				return 0;
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				stk.push(s[i]);
			else if (!stk.empty() && (
				(s[i] == ')' && stk.top() == '(') || 
				(s[i] == ']' && stk.top() == '[') || 
				(s[i] == '}' && stk.top() == '{'))) {
				stk.pop();
			}
		}
		return stk.size() == 0;
	}
};