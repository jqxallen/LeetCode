/*
 * Author: Qiang Jia
 * Date: Dec 7, 2013
 * Link: https://leetcode.com/problems/simplify-path/
 * Description:
 *		Given an absolute path for a file (Unix-style), simplify it.
 *		For example,
 *			path = "/home/", => "/home"
 *			path = "/a/./b/../../c/", => "/c"
 *		Corner Cases:
 *			1. Did you consider the case where path = "/../"?
 *				In this case, you should return "/".
 *			2. Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 *				In this case, you should ignore redundant slashes and return "/home/foo".
 */

#include <iostream>
#include <string>
#include <vector>
using namespace::std;

class Solution {
public:
	string simplifyPath(string path) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		path += "/";
		vector<string> symbols;
		size_t pos, off_pos = 0;
		string token;
		while ((pos = path.find("/", off_pos)) != -1) {
			token = path.substr(off_pos, pos - off_pos);
			if (token == "..") {
				if (!symbols.empty())
					symbols.pop_back();
			}
			else if (token != "." && token != "")
				symbols.push_back(token);
			off_pos = pos + 1;
		}
		string final_path = symbols.empty() ? "/" : "";
		for (auto s : symbols)
			final_path += "/" + s;
		return final_path;
	}
};

void main()
{
	string path = "/...";
	Solution solution;
	cout << solution.simplifyPath(path) << endl;
}
