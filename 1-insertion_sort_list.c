#include "sort.h"


/**
 * insertion_sort_list - orts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: The double linkedlist
 * return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr)
	{
		while (curr->prev && curr->n < curr->prev->n)
		{
			tmp = curr;
			if (curr->next)
				curr->next->prev = tmp->prev;

			curr->prev->next = tmp->next;
			curr = curr->prev;
			tmp->prev = curr->prev;
			tmp->next = curr;

			if (curr->prev)
				curr->prev->next = tmp;

			curr->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;

			print_list(*list);
			curr = curr->prev;
		}
		curr = curr->next;
	}
}

/**
 * swap_item - swap big and small item
 * @big_item: Big node item
 * @small_item: Small node item
 * return: void
 */
void swap_item(listint_t *big_item, listint_t *small_item)
{
	listint_t *big_item_prev = big_item->prev;
	listint_t *small_item_next = small_item->next;

	big_item->next = small_item_next;
	small_item_next->prev = big_item;

	small_item->prev = big_item_prev;
	big_item->prev = small_item;
	small_item->next = big_item;
	big_item_prev->next = small_item;
}
