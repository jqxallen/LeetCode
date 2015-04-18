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
			} else {
				prevVal = node->val;
				prevNode = node;
				node = node->next;
			}
		}
		return head;
	}
};
