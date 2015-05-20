/*
 * Author: Qiang Jia
 * Date: Apr 18, 2015
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Description:
 *		Given a sorted linked list, delete all duplicates such that each element appear only once.
 *		For example,
 *			Given 1->1->2, return 1->2.
 *			Given 1->1->2->3->3, return 1->2->3.
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
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head) return NULL;
		int prevVal = head->val;
		ListNode *prevNode = head;
		ListNode *node = prevNode->next, *tmp;
		while (node) {
			if (node->val == prevVal) {
				tmp = node->next;
				delete node;
				prevNode->next = tmp;
				node = tmp;
			}
			else {
				prevVal = node->val;
				prevNode = node;
				node = node->next;
			}
		}
		return head;
	}
};
