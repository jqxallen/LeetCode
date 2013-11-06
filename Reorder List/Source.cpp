#include <iostream>
using namespace::std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *head)
{
	ListNode *node = head;
	while (node) {
		cout << node->val << "->";
		node = node->next;
	}
	cout << "NULL" << endl;
}

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
	ListNode *reverse(ListNode *head) {
		if (!head) return NULL;
		ListNode *prev = head, *curr = prev->next, *tmp = NULL;
		prev->next = NULL;
		while (curr) {
			tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
		return prev;
	}
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		if (!head) return;

		ListNode *tail = head, *node = head, *tmp1 = NULL, *tmp2 = NULL;
		int counter = 0;
		while (node) {
			if (++counter % 2 == 0)
				tail = tail->next;
			node = node->next;
		}

		tail = this->reverse(tail);

		node = head;
		while (tail) {
			tmp1 = node->next;
			tmp2 = tail->next;
			node->next = tail;
			if (tail == tmp1) break;
			tail->next = tmp1;
			node = tmp1;
			tail = tmp2;
		}
    }
};

void main()
{
	ListNode *head = new ListNode(1);
	ListNode *two = new ListNode(2);
	ListNode *three = new ListNode(3);
	ListNode *four = new ListNode(4);
	ListNode *five = new ListNode(5);
	head->next = two;
	two->next = three;
	three->next = four;
	four->next = five;

	print(head);

	Solution solution;
	solution.reorderList(head);

	print(head);

	system("pause");
}