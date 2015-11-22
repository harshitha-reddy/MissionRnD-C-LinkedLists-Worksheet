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

	if ((K == 0) || (K < 0))
		return NULL;
		node *current_node = head;     

		node *previous_node = NULL;
		for (int i = 0; i<K; i++)            
		{
			previous_node = current_node;
			current_node = current_node->next;
		}

		if (K != 0)   
			previous_node->next = current_node->next;
		else        
			head = head->next;
		free(current_node);         
		return head;           

	}
