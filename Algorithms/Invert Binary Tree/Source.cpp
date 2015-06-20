/*
 * Author: Qiang Jia
 * Date: Jun 20, 2015
 * Link: https://leetcode.com/problems/invert-binary-tree/
 * Description:
 *      Invert a binary tree.
 *	           4
 *	         /   \
 *	        2     7
 *	       / \   / \
 *	      1   3 6   9
 *      to
 *	           4
 *	         /   \
 *	        7     2
 *	       / \   / \
 *	      9   6 3   1
 *      Trivia:
 *			This problem was inspired by this original tweet (https://twitter.com/mxcl/status/608682016205344768) by Max Howell (https://twitter.com/mxcl):
 *      Google:
 *			90% of our engineers use the software you wrote (Homebrew), but you can¡¯t invert a binary tree on a whiteboard so fuck off.
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
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return NULL;
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};
