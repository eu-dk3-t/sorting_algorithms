#include "sort.h"

/**
 * Function name:
 * 	insertion_sort_list 
 * Description:
 * 	Implementation of the insertion sort algorithm.
 * NTK:
 * 	@list: A double pointer to the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur;
	listint_t *prv;
	listint_t *nxt;

	if (list == NULL || *list == NULL)
		return;

	cur = (*list)->next;
	while (cur != NULL)
	{
		nxt = cur->next;
		prv = cur->prev;
		if (prv && cur->n < prv->n)
		{
			prv->next = cur->next;
			if (nxt != NULL)
				nxt->prev = prv;
			prv = prv->prev;
			if (prv == NULL)
			{
				cur->prev = NULL;
				cur->next = *list;
				(*list)->prev = cur;
				*list = cur;
			}
			else
			{
				cur->prev = prv;
				cur->next = prv->next;
				prv->next->prev = cur;
				prv->next = cur;
			}
			print_list(*list);
		}
		else
			cur = nxt;
	}
}
