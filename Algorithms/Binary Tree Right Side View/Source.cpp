/*
 * Author: Qiang Jia
 * Date: Apr 12, 2015
 * Link: https://leetcode.com/problems/binary-tree-right-side-view/
 * Description:
 *      Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 *      For example:
 *          Given the following binary tree,
 *             1            <---
 *           /   \
 *          2     3         <---
 *           \     \
 *            5     4       <---
 *          You should return [1, 3, 4].
 */

#include <iostream>
#include <vector>
#include <iterator>
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
	vector<int> rightSideView(TreeNode *root) {
		vector<int> v;
		if (!root) return v;
		vector<TreeNode*> level;
		level.push_back(root);
		this->iterateByLevel(level, v);
		return v;
	}
	void iterateByLevel(vector<TreeNode*> level, vector<int> &v) {
		if (level.empty()) return;
		v.push_back(level[level.size() - 1]->val);
		vector<TreeNode*> next;
		for (auto it = level.cbegin(); it != level.cend(); ++it) {
			if ((*it)->left) next.push_back((*it)->left);
			if ((*it)->right) next.push_back((*it)->right);
		}
		this->iterateByLevel(next, v);
	}
};

void main() {
	TreeNode *root = new TreeNode(1);
	TreeNode *two = new TreeNode(2);
	TreeNode *three = new TreeNode(3);
	TreeNode *four = new TreeNode(4);
	TreeNode *five = new TreeNode(5);
	root->left = two;
	root->right = three;
	two->right = five;
	three->right = four;
	Solution solution;
	vector<int> v = solution.rightSideView(root);
	copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
}
