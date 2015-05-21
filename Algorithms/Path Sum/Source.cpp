/*
 * Author: Qiang Jia
 * Date: Nov 6, 2013
 * Link: https://leetcode.com/problems/path-sum/
 * Description:
 *		Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 *		For example:
 *			Given the below binary tree and sum = 22,
 *			              5
 *			             / \
 *			            4   8
 *			           /   / \
 *			          11  13  4
 *			         /  \      \
 *			        7    2      1
 *			return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
	bool hasPathSum(TreeNode *root, int sum) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!root) return 0;
		if (!root->left && !root->right) return sum - root->val == 0;
		if (hasPathSum(root->left, sum - root->val)) return 1;
		if (hasPathSum(root->right, sum - root->val)) return 1;
		return 0;
	}
};
