/*
 * Author: Qiang Jia
 * Date: Nov 14, 2013
 * Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * Description:
 *		Given a binary tree
 *		    struct TreeLinkNode {
 *		      TreeLinkNode *left;
 *		      TreeLinkNode *right;
 *		      TreeLinkNode *next;
 *		    }
 *		Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 *		Initially, all next pointers are set to NULL.
 *		Note:
 *			You may only use constant extra space.
 *			You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 *		For example,
 *			Given the following perfect binary tree,
 *			         1
 *			       /  \
 *			      2    3
 *			     / \  / \
 *			    4  5  6  7
 *			After calling your function, the tree should look like:
 *			         1 -> NULL
 *			       /  \
 *			      2 -> 3 -> NULL
 *			     / \  / \
 *			    4->5->6->7 -> NULL
 */

#include <iostream>
#include <queue>
using namespace::std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution {
public:
	void connect(TreeLinkNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!root) return;
		queue<TreeLinkNode*> coll;
		coll.push(root);
		int counter = 1, tmp_counter = 0;
		TreeLinkNode *prev = NULL, *curr = NULL;
		while (!coll.empty()) {
			tmp_counter = 0;
			prev = NULL;
			while (counter--) {
				curr = coll.front();
				if (!prev) prev = curr;
				else prev->next = curr, prev = curr;
				coll.pop();
				if (curr->left)
					coll.push(curr->left), tmp_counter++;
				if (curr->right)
					coll.push(curr->right), tmp_counter++;
			}
			counter = tmp_counter;
		}
	}
};

void main()
{
	TreeLinkNode *root = new TreeLinkNode(1);
	TreeLinkNode *two = new TreeLinkNode(2);
	TreeLinkNode *three = new TreeLinkNode(3);
	TreeLinkNode *four = new TreeLinkNode(4);
	TreeLinkNode *five = new TreeLinkNode(5);
	TreeLinkNode *six = new TreeLinkNode(6);
	TreeLinkNode *seven = new TreeLinkNode(7);
	root->left = two;
	root->right = three;
	two->left = four;
	two->right = five;
	three->left = six;
	three->right = seven;
	Solution solution;
	solution.connect(root);
}
