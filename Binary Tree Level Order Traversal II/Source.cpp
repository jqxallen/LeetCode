#include <iostream>
#include <stack>
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
	void bottom_order_recur(vector<vector<int>> &colls, const vector<TreeNode*> &coll) {
		if (coll.empty()) return;
		vector<TreeNode*> temp_coll;
		for (TreeNode *node : coll) {
			if (node->left) temp_coll.push_back(node->left);
			if (node->right) temp_coll.push_back(node->right);
		}
		if (!temp_coll.empty()) this->bottom_order_recur(colls, temp_coll);
		vector<int> val_coll;
		for (TreeNode *node : coll)
			val_coll.push_back(node->val);
		colls.push_back(val_coll);
	}
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<vector<int>> colls;
		if (!root) return colls;
		vector<TreeNode*> coll;
		coll.push_back(root);
		this->bottom_order_recur(colls, coll);
		return colls;
	}
};