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