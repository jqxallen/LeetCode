#include <iostream>
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
	void print(TreeNode *root) const {
		if (!root) return;
		cout << root->val << endl;
		if (root->left) this->print(root->left);
		if (root->right) this->print(root->right);
	}
	TreeNode *flatten_recur(TreeNode *root) {
		if (!root || (!root->left && !root->right)) return root;
		TreeNode *right = root->right, *node = NULL;
		if (root->left) {
			node = this->flatten_recur(root->left);
			root->right = root->left;
		}
		root->left = NULL;
		if (right) {
			root = this->flatten_recur(right);
			if (node) node->right = right;
			node = root;
		}
		return node;
	}
	void flatten(TreeNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		this->flatten_recur(root);
	}
};

void main()
{
	TreeNode *one = new TreeNode(1);
	TreeNode *two = new TreeNode(2);
	TreeNode *three = new TreeNode(3);
	TreeNode *four = new TreeNode(4);
	TreeNode *five = new TreeNode(5);
	TreeNode *six = new TreeNode(6);
	one->left = two, one->right = five;
	two->left = three, two->right = four;
	five->right = six;

	Solution solution;
	solution.print(one);
	solution.flatten(one);
	solution.print(one);

	system("pause");
}