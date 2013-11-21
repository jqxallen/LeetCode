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