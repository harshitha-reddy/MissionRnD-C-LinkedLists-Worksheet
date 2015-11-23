/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	if ((head == NULL))
		return NULL;


	struct node *curr, *largest, *largestPrev, *prev, *tmp;
	curr = head;
	largest = head;
	prev = head;
	largestPrev = head;
	while (curr != NULL)
	{
		if (curr->num < largest->num)
		{
			largestPrev = prev;
			largest = curr;
		}
		prev = curr;
		curr = curr->next;

	}

	if (largest != head)
	{
		largestPrev->next = head;
		tmp = head->next;
		head->next = largest->next;
		largest->next = tmp;
	}

	
	largest->next = sortLinkedList(largest->next);
	return largest;

	
}



