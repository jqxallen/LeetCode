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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!l1) return l2;
		if (!l2) return l1;

		int carry = l1->val + l2->val;
		ListNode * l = new ListNode(carry % 10);
		carry /= 10;

		ListNode * n = l, * n1 = l1->next, * n2 = l2->next;

		while (n1 && n2) {
			carry += n1->val + n2->val;
			n->next = new ListNode(carry % 10);
			carry /= 10;
			n = n->next;
			n1 = n1->next;
			n2 = n2->next;
		}

		while (n1) {
			carry += n1->val;
			n->next = new ListNode(carry % 10);
			carry /= 10;
			n = n->next;
			n1 = n1->next;
		}

		while (n2) {
			carry += n2->val;
			n->next = new ListNode(carry % 10);
			carry /= 10;
			n = n->next;
			n2 = n2->next;
		}

		if (carry) n->next = new ListNode(carry);

		return l;
    }
};