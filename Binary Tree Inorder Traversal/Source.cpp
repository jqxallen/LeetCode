#include <iostream>
#include <vector>
#include <stack>
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
	vector<int> inorderTraversal(TreeNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<int> coll;
		stack<TreeNode*> s;
		TreeNode *node = root;
		while (!s.empty() || node) {
			if (node) {
				s.push(node);
				node = node->left;
			}
			else {
				coll.push_back(s.top()->val);
				node = s.top()->right;
				s.pop();
			}
		}
		return coll;
	}
};

void main()
{
	TreeNode *root = new TreeNode(1);

	Solution solution;
	vector<int> coll = solution.inorderTraversal(root);

	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, "\n"));

	system("pause");
}