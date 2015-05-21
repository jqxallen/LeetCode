/*
 * Author: Qiang Jia
 * Date: Nov 6, 2013
 * Link: https://leetcode.com/problems/same-tree/
 * Description:
 *		Given two binary trees, write a function to check if they are equal or not.
 *		Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
	bool isSameTree(TreeNode *p, TreeNode *q) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!p && !q)
			return 1;
		else if (p && q)
			return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		else
			return 0;
	}
};
