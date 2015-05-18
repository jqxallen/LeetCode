/*
 * Author: Qiang Jia
 * Date: Nov 8, 2013
 * Link: https://leetcode.com/problems/validate-binary-search-tree/
 * Description:
 *		Given a binary tree, determine if it is a valid binary search tree (BST).
 *		Assume a BST is defined as follows:
 *			1. The left subtree of a node contains only nodes with keys less than the node's key.
 *			2. The right subtree of a node contains only nodes with keys greater than the node's key.
 *			3. Both the left and right subtrees must also be binary search trees.
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
	bool _isValidBST_(TreeNode *root, int min, int max) {
		if (!root) return 1;
		bool tf = root->val > min && root->val < max;
		bool lf = root->left ? root->left->val < root->val : 1;
		bool rf = root->right ? root->val < root->right->val : 1;
		return tf && lf && rf &&
			_isValidBST_(root->left, min, root->val) &&
			_isValidBST_(root->right, root->val, max);
	}
	bool isValidBST(TreeNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		return this->_isValidBST_(root, INT_MIN, INT_MAX);
	}
};
