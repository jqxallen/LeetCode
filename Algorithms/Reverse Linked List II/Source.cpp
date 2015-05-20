/*
 * Author: Qiang Jia
 * Date: Nov 6, 2013
 * Link: https://leetcode.com/problems/reverse-linked-list-ii/
 * Description:
 *		Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *		For example:
 *			Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *			return 1->4->3->2->5->NULL.
 *		Note:
 *			Given m, n satisfy the following condition:
 *			1 <= m <= n <= length of list.
 */

#include <iostream>
using namespace::std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!head) return NULL;
		ListNode *_head_ = (m - 1) ? head : NULL;
		n -= m;
		/* skip first m-1 nodes */
		ListNode *tail = (m - 1) ? head : NULL;
		while (--m > 1) tail = tail->next;
		/* reverse n-m nodes */
		ListNode *prev = tail ? tail->next : head;
		ListNode *curr = prev->next ? prev->next : NULL;
		ListNode *tmp = NULL;
		prev->next = NULL;
		while (curr && n--) {
			tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
		/* combine three separate list */
		if (!_head_) _head_ = prev;
		else tail->next = prev;
		while (prev->next) prev = prev->next;
		prev->next = curr;
		return _head_;
	}
};

void main()
{
	ListNode * head = new ListNode(3);
	head->next = new ListNode(5);
	Solution solution;
	ListNode * node = solution.reverseBetween(head, 2, 2);
	while (node) {
		cout << node->val << "->";
		node = node->next;
	}
	cout << "NULL" << endl;
}
