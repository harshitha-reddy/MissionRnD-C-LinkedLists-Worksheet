/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {

		struct node *q, *p;

		int count = 1;

		p = head;
		q = NULL;
		if ((head == 0) || (K <= 1))
			return NULL;
		
			while ((p->next != NULL))
			{
				q = p;

				p = p->next;
				count++;

				if (count%K == 0)
				{
					q->next = p->next;

				}
			}

			return head;

		
	}
