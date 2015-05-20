/*
 * Author: Qiang Jia
 * Date: Nov 17, 2013
 * Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * Description:
 *		Given a binary tree, find its maximum depth.
 *		The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

#include <iostream>
#include <algorithm>
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
	int maxDepth(TreeNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!root) return 0;
		if (!root->left && !root->right) return 1;
		return 1 + max(this->maxDepth(root->left), this->maxDepth(root->right));
	}
};
