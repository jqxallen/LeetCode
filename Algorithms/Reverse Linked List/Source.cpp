/*
 * Author: Qiang Jia
 * Date: May 6, 2015
 * Link: https://leetcode.com/problems/reverse-linked-list/
 * Description:
 *		Reverse a singly linked list.
 *		Hint:
 *			A linked list can be reversed either iteratively or recursively. Could you implement both?
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
	ListNode* reverseList(ListNode* head) {
		if (!head)
			return NULL;
		ListNode *prev = head, *curr = prev->next, *next;
		prev->next = NULL;
		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}
};
