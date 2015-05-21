/*
 * Author: Qiang Jia
 * Date: Nov 21, 2013
 * Link: https://leetcode.com/problems/sort-list/
 * Description:
 *		Sort a linked list in O(n log n) time using constant space complexity.
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
	ListNode *sortList(ListNode *head) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!head || !head->next) return head;
		/* divide into two lists */
		ListNode *last = NULL, *tail = head, *node = head;
		int counter = 0;
		while (node) {
			if (++counter % 2 == 0)
				last = tail, tail = tail->next;
			node = node->next;
		}
		if (last) last->next = NULL;
		/* sort two separate lists */
		ListNode *curr1 = this->sortList(head);
		ListNode *curr2 = this->sortList(tail);
		/* merge two separate lists */
		if (curr1->val < curr2->val) head = curr1, curr1 = curr1->next;
		else head = curr2, curr2 = curr2->next;
		node = head;
		while (curr1 && curr2) {
			if (curr1->val < curr2->val) node->next = curr1, curr1 = curr1->next;
			else node->next = curr2, curr2 = curr2->next;
			node = node->next;
		}
		if (curr1) node->next = curr1;
		else node->next = curr2;
		return head;
	}
	void print(ListNode *head) const {
		ListNode *node = head;
		while (node) cout << node->val << "->", node = node->next;
		cout << "null" << endl;
	}
};

void main()
{
	ListNode *two = new ListNode(2);
	ListNode *five = new ListNode(5);
	ListNode *three = new ListNode(3);
	ListNode *one = new ListNode(1);
	ListNode *four = new ListNode(4);
	two->next = five;
	five->next = three;
	three->next = one;
	one->next = four;
	Solution solution;
	solution.print(two);
	ListNode *head = solution.sortList(two);
	solution.print(head);
}
