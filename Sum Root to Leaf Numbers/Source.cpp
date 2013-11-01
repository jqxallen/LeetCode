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
	void calc_recur(TreeNode * root, int val, int &sum) {
		if (!root->left && !root->right) {
			sum += val * 10 + root->val;
			return;
		}
		
		if (root->left) {
			calc_recur(root->left, val * 10 + root->val, sum);
		}

		if (root->right) {
			calc_recur(root->right, val * 10 + root->val, sum);
		}
	}
    int sumNumbers(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		if (!root) return 0;

		int sum = 0;
		calc_recur(root, 0, sum);
		return sum;
    }
};