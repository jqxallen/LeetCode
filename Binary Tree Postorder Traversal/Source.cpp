#include <iostream>
#include <vector>
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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> coll;
		if (!root) return coll;

		stack<pair<TreeNode*, bool>> s;
		s.push(make_pair(root, 1));
		if (root->right) s.push(make_pair(root->right, 0));
		if (root->left) s.push(make_pair(root->left, 0));
		pair<TreeNode*, bool> p;
		while (!s.empty()) {
			p = s.top();
			if ((!p.first->left && !p.first->right) || p.second) {
				coll.push_back(p.first->val);
				s.pop();
			} else {
				s.top().second = 1;
				if (p.first->right) s.push(make_pair(p.first->right, 0));
				if (p.first->left) s.push(make_pair(p.first->left, 0));
			}			
		}

		return coll;
    }
};