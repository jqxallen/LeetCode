/*
 * Author: Qiang Jia
 * Date: Nov 21, 2013
 * Link: https://leetcode.com/problems/symmetric-tree/
 * Description:
 *		Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *		For example, this binary tree is symmetric:
 *			    1
 *			   / \
 *			  2   2
 *			 / \ / \
 *			3  4 4  3
 *		But the following is not:
 *			    1
 *			   / \
 *			  2   2
 *			   \   \
 *			   3    3
 *		Note:
 *			Bonus points if you could solve it both recursively and iteratively.
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
	bool is_symmetric(TreeNode *left, TreeNode *right) {
		if (!left && !right) return 1;
		if (left && right)
			return (left->val == right->val) &&
			this->is_symmetric(left->left, right->right) &&
			this->is_symmetric(left->right, right->left);
		return 0;
	}
	bool isSymmetric(TreeNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!root) return 1;
		return this->is_symmetric(root->left, root->right);
	}
};
