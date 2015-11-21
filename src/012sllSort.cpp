/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
		int count[3] = { 0, 0, 0 };
		struct node *ptr = head;
		while (ptr != NULL)
		{
			count[ptr->data] += 1;
			ptr = ptr->next;
		}

		int i = 0;
		ptr = head;
		while (ptr != NULL)
		{
			if (count[i] == 0)
				++i;
			else
			{
				ptr->data = i;
				--count[i];
				ptr = ptr->next;
			}
		}
	}

	void push(struct node** head_ref, int new_data)
	{
		struct node* new_node =
			(struct node*) malloc(sizeof(struct node));
		new_node->data = new_data;

		new_node->next = (*head_ref);
		(*head_ref) = new_node;
	}
	void printList(struct node *node)
	{
		while (node != NULL)
		{
			printf("%d  ", node->data);
			node = node->next;
		}
		printf("\n");
	}
