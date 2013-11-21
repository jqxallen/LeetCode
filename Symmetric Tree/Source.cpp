#include <iostream>

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