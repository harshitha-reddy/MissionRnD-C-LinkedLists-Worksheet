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

/*	struct node  *curr, *prev, *temp;
	//int temp;
	curr = head;
	prev = NULL;
	while (curr->next != NULL)
	{
		prev = curr;
		while (prev != curr)
		{

			if (curr->num > curr->next->num)
			{
				temp = curr->next->next;
				prev->next = curr->next;
				curr->next = NULL;
				prev->next->next = curr;
				curr->next = temp;
			}
		}


		curr = curr->next;
	}
*/
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
	//largest node is in largest.
	//2- switching firt node and largest node :
	//struct node *tmp;
	if (largest != head)
	{
		largestPrev->next = head;
		tmp = head->next;
		head->next = largest->next;
		largest->next = tmp;
	}

	// now largest is the first node of the list.
	// calling the function again with the sub list :
	// list minus its first node :
	largest->next = sortLinkedList(largest->next);
	return largest;

	//return 0;
}



