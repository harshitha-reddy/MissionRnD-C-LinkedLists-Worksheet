/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

void dis(struct node **list)
{
	struct node *prev, *current, *nexte;
	prev = NULL;
	current = *list;
	nexte = current->next;
	while (current->next != NULL)
	{
		current->next = prev;
		prev = current;
		current = nexte;
		nexte = nexte->next;
	}
	current->next = prev;
	*list = current;
}
void create(struct node **list, int N)
{
	struct node *temp, *p;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->next = NULL;
	temp->num = N;
	if (*list == NULL)
	{
		*list = temp;
	}
	else
	{
		p = *list;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}
}
struct node * numberToLinkedList(int N) {
	if (N < 0)
		N = -N;
	int x;
	struct node *list, *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	list = NULL;
	if (N == 0)
	{
		temp->num = 0;
		temp->next = NULL;
		list = temp;
	}
	else
	{
		while (N > 0)
		{
			x = N % 10;
			create(&list, x);
			N = N / 10;
		}
	}
	dis(&list);
	return list;
}
