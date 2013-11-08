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
	bool _isValidBST_(TreeNode *root, int min, int max) {
		if (!root) return 1;
		bool tf = root->val > min && root->val < max;
		bool lf = root->left? root->left->val < root->val: 1;
		bool rf = root->right? root->val < root->right->val: 1;
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