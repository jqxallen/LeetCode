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

	system("pause");
}