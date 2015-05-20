/*
 * Author: Qiang Jia
 * Date: Nov 8, 2013
 * Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
 * Description:
 *		Given a binary tree, return the preorder traversal of its nodes' values.
 *		For example:
 *			Given binary tree {1,#,2,3},
 *			   1
 *			    \
 *			     2
 *			    /
 *			   3
 *			return [1,2,3].
 *		Note:
 *			Recursive solution is trivial, could you do it iteratively?
 */

#include <iostream>
#include <vector>
#include <stack>
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
	vector<int> preorderTraversal(TreeNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<int> coll;
		if (!root) return coll;
		stack<TreeNode*> s;
		s.push(root);
		TreeNode* node;
		while (!s.empty()) {
			node = s.top();
			s.pop();
			coll.push_back(node->val);
			if (node->right) s.push(node->right);
			if (node->left) s.push(node->left);
		}
		return coll;
	}
};
