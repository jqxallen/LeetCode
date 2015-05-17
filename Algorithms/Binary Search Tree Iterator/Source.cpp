/*
 * Author: Qiang Jia
 * Date: Apr 13, 2015
 * Link: https://leetcode.com/problems/binary-search-tree-iterator/
 * Description:
 *      Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 *      Calling next() will return the next smallest number in the BST.
 *      Note:
 *          next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 */

#include <iostream>
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
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		this->push_left(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *tmp = s.top();
		s.pop();
		TreeNode *node = tmp->right;
		if (node) {
			s.push(node);
			this->push_left(node->left);
		}
		return tmp->val;
	}
private:
	void push_left(TreeNode *node) {
		while (node) {
			s.push(node);
			node = node->left;
		}
	}
	stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

void main()
{
	TreeNode *root = new TreeNode(4);
	TreeNode *one = new TreeNode(1);
	TreeNode *two = new TreeNode(2);
	TreeNode *three = new TreeNode(3);
	TreeNode *five = new TreeNode(5);
	TreeNode *six = new TreeNode(6);
	TreeNode *seven = new TreeNode(7);
	root->left = two;
	root->right = six;
	two->left = one;
	two->right = three;
	six->left = five;
	six->right = seven;
	BSTIterator i = BSTIterator(root);
	while (i.hasNext())
		cout << i.next();
}
