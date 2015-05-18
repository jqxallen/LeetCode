/*
 * Author: Qiang Jia
 * Date: Nov 21, 2013
 * Link: https://leetcode.com/problems/swap-nodes-in-pairs/
 * Description:
 *		Given a linked list, swap every two adjacent nodes and return its head.
 *		For example,
 *			Given 1->2->3->4, you should return the list as 2->1->4->3.
 *			Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */

#include <iostream>

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
	ListNode *swapPairs(ListNode *head) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!head || !head->next) return head;
		ListNode *tail = NULL, *prev = head, *curr = head->next;
		while (curr) {
			prev->next = curr->next;
			curr->next = prev;
			if (prev == head) head = curr;
			if (tail) tail->next = curr;
			tail = prev;
			prev = prev->next;
			if (!prev) break;
			curr = prev->next;
		}
		return head;
	}
};
