/*
 * Author: Qiang Jia
 * Date: Nov 16, 2013
 * Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
 * Description:
 * 		Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * 		For example:
 * 			Given binary tree {3,9,20,#,#,15,7},
 * 			    3
 * 			   / \
 *			   9  20
 *			     /  \
 *			    15   7
 *			return its level order traversal as:
 *			[
 *				[3],
 *				[9,20],
 *				[15,7]
 *			]
 */

#include <iostream>
#include <vector>
#include <queue>
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
	vector<vector<int> > levelOrder(TreeNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<vector<int>> colls;
		if (!root) return colls;
		queue<TreeNode*> coll;
		coll.push(root);
		int counter = 1, temp_counter = 0;
		TreeNode *node;
		while (!coll.empty()) {
			temp_counter = 0;
			vector<int> val_coll;
			while (counter--) {
				node = coll.front();
				val_coll.push_back(node->val);
				coll.pop();
				if (node->left) coll.push(node->left), temp_counter++;
				if (node->right) coll.push(node->right), temp_counter++;
			}
			counter = temp_counter;
			colls.push_back(val_coll);
		}
		return colls;
	}
};
