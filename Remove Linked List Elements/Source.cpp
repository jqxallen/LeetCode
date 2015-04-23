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
