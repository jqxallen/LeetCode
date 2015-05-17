/*
 * Author: Qiang Jia
 * Date: Nov 6, 2013
 * Link: https://leetcode.com/problems/balanced-binary-tree/
 * Description:
 *		Given a binary tree, determine if it is height-balanced.
 *		For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
	int height(TreeNode *root) {
		if (!root) return 0;
		return 1 + max(height(root->left), height(root->right));
	}
	bool isBalanced(TreeNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!root) return 1;
		return abs(height(root->left) - height(root->right)) < 2 &&
			isBalanced(root->left) && isBalanced(root->right);
	}
};
