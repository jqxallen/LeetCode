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