#include <iostream>

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		if (!head) return NULL;
		/* make new copied node */
		RandomListNode * node = head;
		while (node) {
			RandomListNode * new_node = new RandomListNode(node->label);
			new_node->next = node->next;
			node->next = new_node;
			node = node->next->next;
		}
		/* assign random field of copied node */
		node = head;
		while (node) {
			if (node->random)
				node->next->random = node->random->next;
			node = node->next->next;
		}
		/* separate new copied list */
		RandomListNode * new_head = head->next;
		node = head;
		while (node) {
			RandomListNode * new_node = node->next;
			node->next = node->next->next;
			if (node->next)
				new_node->next = node->next->next;
			node = node->next;
		}
		return new_head;
    }
};