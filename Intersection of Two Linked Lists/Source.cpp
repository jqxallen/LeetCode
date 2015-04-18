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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int i = 0, j = 0;
		ListNode *node1 = headA, *node2 = headB;
		while (node1) ++i, node1 = node1->next;
		while (node2) ++j, node2 = node2->next;
		node1 = headA, node2 = headB;
		while ((i - j) > 0) --i, node1 = node1->next;
		while ((j - i) > 0) --j, node2 = node2->next;
		while (node1 && node2) {
			if (node1 == node2)
				return node1;
			node1 = node1->next;
			node2 = node2->next;
		}
		return NULL;
	}
};
