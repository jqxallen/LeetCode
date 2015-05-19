/*
 * Author: Qiang Jia
 * Date: Nov 13, 2013
 * Link: https://leetcode.com/problems/insertion-sort-list/
 * Description:
 *		Sort a linked list using insertion sort.
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
	ListNode *insertionSortList(ListNode *head) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!head) return NULL;
		ListNode *prev = head, *curr = prev->next;
		while (curr) {
			if (curr->val < prev->val) {
				ListNode *tmp = curr;
				prev->next = curr->next;
				curr = prev->next;
				if (tmp->val < head->val) {
					tmp->next = head;
					head = tmp;
				}
				else {
					ListNode* _prev = head, *_curr = _prev->next;
					while (_curr) {
						if (tmp->val < _curr->val) {
							_prev->next = tmp;
							tmp->next = _curr;
							break;
						}
						else {
							_prev = _curr;
							_curr = _curr->next;
						}
					}
				}
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
		return head;
	}
};
