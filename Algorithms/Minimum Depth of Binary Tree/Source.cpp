/*
 * Author: Qiang Jia
 * Date: Nov 6, 2013
 * Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * Description:
 *		Given a binary tree, find its minimum depth.
 *		The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */

#include <iostream>
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
	void min(TreeNode *root, int &min, int curr_min) {
		if (!root) return;
		if (!root->left && !root->right && curr_min + 1 < min) {
			min = curr_min + 1;
			return;
		}
		this->min(root->left, min, curr_min + 1);
		this->min(root->right, min, curr_min + 1);
	}
	int minDepth(TreeNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!root) return 0;
		int min = INT_MAX;
		this->min(root, min, 0);
		return min;
	}
};
