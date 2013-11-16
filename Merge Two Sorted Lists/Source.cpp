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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!l1 && !l2) return NULL;
		if (!l1) return l2;
		if (!l2) return l1;

		/* set head pointer */
		ListNode *head, *node, *curr1 = l1, *curr2 = l2;
		if (l1->val < l2->val) {
			head = l1;
			curr1 = l1->next;
		}
		else {
			head = l2;
			curr2 = l2->next;
		}
		node = head;

		/* merge linked lists */
		while (curr1 && curr2) {
			if (curr1->val < curr2->val)
				node->next = curr1, curr1 = curr1->next;
			else
				node->next = curr2, curr2 = curr2->next;
			node = node->next;
		}

		/* append remaining nodes if existed */
		if (curr1) node->next = curr1;
		else node->next = curr2;

		return head;
	}
};