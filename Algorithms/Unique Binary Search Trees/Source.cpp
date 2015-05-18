/*
 * Author: Qiang Jia
 * Date: Dec 5, 2013
 * Link: https://leetcode.com/problems/unique-binary-search-trees/
 * Description:
 *		Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *		For example,
 *			Given n = 3, there are a total of 5 unique BST's.
 *			   1         3     3      2      1
 *			    \       /     /      / \      \
 *			     3     2     1      1   3      2
 *			    /     /       \                 \
 *			   2     1         2                 3
 */

#include <iostream>
using namespace::std;

class Solution {
public:
	int numTrees(int begin, int end) {
		if (begin >= end) return 1;
		int count = 0;
		for (int i = begin; i <= end; ++i)
			count += this->numTrees(begin, i - 1) * this->numTrees(i + 1, end);
		return count;
	}
	int numTrees(int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		return this->numTrees(1, n);
	}
};

void main()
{
	Solution solution;
	cout << solution.numTrees(3) << endl;
}
