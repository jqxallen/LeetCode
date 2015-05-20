/*
 * Author: Qiang Jia
 * Date: Apr 23, 2015
 * Link: https://leetcode.com/problems/remove-linked-list-elements/
 * Description:
 *		Remove all elements from a linked list of integers that have value val.
 *		Example
 *			Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 *			Return: 1 --> 2 --> 3 --> 4 --> 5
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
	ListNode* removeElements(ListNode* head, int val) {
		if (!head) return NULL;
		ListNode* node = head, *tmp;
		while (node && node->val == val) {
			tmp = node;
			node = node->next;
			delete tmp;
		}
		head = node;//prev = node;
		while (node && node->next) {
			if (node->next->val == val) {
				ListNode* tmp = node->next;
				node->next = node->next->next;
				delete tmp;
			}
			else {
				node = node->next;
			}
		}
		return head;
	}
};
