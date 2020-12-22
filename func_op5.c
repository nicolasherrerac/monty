#include "monty.h"

/**
 * rotl - Rotate the stack to the top.
 * @s_head: Pointer to the head of the stack.
 * @line_number: Currrent line number.
 */
void rotl(stack_t **s_head, unsigned int line_number)
{
	stack_t *current;
	int tmp;

	if ((*s_head) == NULL)
		return;

	current = *s_head;
	tmp = (*s_head)->n;

	/*Shift values one node*/
	for (; current->next; current = current->next)
		current->n = current->next->n;

	current->n = tmp;

	(void)line_number;
}

/**
 * rotr - Rotate the stack to the bottom.
 * @s_head: Pointer to the head of the stack.
 * @line_number: Currrent line number.
 */
void rotr(stack_t **s_head, unsigned int line_number)
{
	stack_t *new, *last = *s_head;
	int tmp;

	if ((*s_head) == NULL || (*s_head)->next == NULL)
		return;

	/*Find the last node*/
	for (; last->next; last = last->next)
		;

	tmp = last->n;
	(last->prev)->next = NULL;
	free(last);

	/*Create new node*/
	new = malloc(sizeof(stack_t));
	if (!new)
		prt_error(-1);

	new->n = tmp;
	new->prev = NULL;
	new->next = *s_head;

	(*s_head)->prev = new;

	*s_head = new;

	(void)line_number;
}
