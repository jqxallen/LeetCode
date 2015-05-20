/*
 * Author: Qiang Jia
 * Date: Apr 19, 2015
 * Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
 * Description:
 *		Write a program to find the node at which the intersection of two singly linked lists begins.
 *		For example, the following two linked lists:
 *			A:          a1 -> a2
 *			                   ->
 *			                     c1 -> c2 -> c3
 *			                   ->
 *			B:     b1 -> b2 -> b3
 *			begin to intersect at node c1.
 *		Notes:
 *			1. If the two linked lists have no intersection at all, return null.
 *			2. The linked lists must retain their original structure after the function returns.
 *			3. You may assume there are no cycles anywhere in the entire linked structure.
 *			4. Your code should preferably run in O(n) time and use only O(1) memory.
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
