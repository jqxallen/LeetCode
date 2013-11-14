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