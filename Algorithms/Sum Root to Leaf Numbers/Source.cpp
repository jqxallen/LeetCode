/*
 * Author: Qiang Jia
 * Date: Nov 1, 2013
 * Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/
 * Description:
 *		Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *		An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *		Find the total sum of all root-to-leaf numbers.
 *		For example,
 *			    1
 *			   / \
 *			  2   3
 *			The root-to-leaf path 1->2 represents the number 12.
 *			The root-to-leaf path 1->3 represents the number 13.
 *			Return the sum = 12 + 13 = 25.
 */

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
