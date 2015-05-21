/*
 * Author: Qiang Jia
 * Date: Nov 14, 2013
 * Link: https://leetcode.com/problems/path-sum-ii/
 * Description:
 *		Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *		For example:
 *			Given the below binary tree and sum = 22,
 *			              5
 *			             / \
 *			            4   8
 *			           /   / \
 *			          11  13  4
 *			         /  \    / \
 *			        7    2  5   1
 *			return
 *			[
 *			   [5,4,11,2],
 *			   [5,8,4,5]
 *			]
 */

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
	void find_path(vector<vector<int>> &colls, vector<int> &coll, TreeNode *root, int sum) {
		if (!root) return;
		if (!root->left && !root->right) {
			if (root->val != sum) return;
			coll.push_back(root->val);
			vector<int> temp_coll(coll);
			colls.push_back(temp_coll);
			coll.pop_back();
		}
		else {
			coll.push_back(root->val);
			this->find_path(colls, coll, root->left, sum - root->val);
			this->find_path(colls, coll, root->right, sum - root->val);
			coll.pop_back();
		}
	}
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<vector<int>> colls;
		vector<int> coll;
		this->find_path(colls, coll, root, sum);
		return colls;
	}
};
