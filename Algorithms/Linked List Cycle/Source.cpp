/*
 * Author: Qiang Jia
 * Date: Nov 1, 2013
 * Link: https://leetcode.com/problems/linked-list-cycle/
 * Description:
 *		Given a linked list, determine if it has a cycle in it.
 *		Follow up:
 *			Can you solve it without using extra space?
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
	bool hasCycle(ListNode *head) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!head || !head->next) return 0;
		ListNode * slower = head;
		ListNode * faster = head->next;
		while (slower && faster) {
			if (slower == faster) return 1;
			if (!faster->next) return 0;
			else faster = faster->next->next;
			slower = slower->next;
		}
		return 0;
	}
};
