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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<vector<int>> colls;
		if (!root) return colls;
		queue<TreeNode*> coll;
		coll.push(root);
		int counter = 1, temp_counter = 0;
		bool left2right = 1;
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
			if (left2right) left2right = 0;
			else left2right = 1, reverse(val_coll.begin(), val_coll.end());
			colls.push_back(val_coll);
		}
		return colls;
	}
};