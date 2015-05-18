/*
 * Author: Qiang Jia
 * Date: Nov 21, 2013
 * Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * Description:
 *		Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */

#include <iostream>
#include <vector>
using namespace::std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode *build_BST(const vector<int> &num, int i, int j) {
		if (i > j) return NULL;
		else if (i == j) return new TreeNode(num[i]);
		else {
			int k = (i + j) / 2;
			TreeNode *root = new TreeNode(num[k]);
			root->left = this->build_BST(num, i, k - 1);
			root->right = this->build_BST(num, k + 1, j);
			return root;
		}
	}
	TreeNode *sortedArrayToBST(vector<int> &num) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		return this->build_BST(num, 0, num.size() - 1);
	}
};
