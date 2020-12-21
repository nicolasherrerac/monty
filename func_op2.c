#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void pint(stack_t **s_head, unsigned int line_number)
{
	if ((*s_head) == NULL)
		prt_error(-3);
	printf("%d\n", (*s_head)->n);
}

/**
 * pop - removes the top element of the stack.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void pop(stack_t **s_head, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*s_head) == NULL)
		prt_error(-3);

	next = (*s_head)->next;
	free(*s_head);
	if (next)
		next->prev = NULL;
	*s_head = next;
}

/**
 * swap - swaps the top two elements of the stack.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void swap(stack_t **s_head, unsigned int line_number)
{
	stack_t *temp;

	if (*s_head == NULL || (*s_head)->next == NULL)
		prt_error(-4);

	temp = (*s_head)->next;
	(*s_head)->prev = temp;
	(*s_head)->next = temp->next;
	temp->next = (*s_head);
	temp->prev = NULL;
	*s_head = temp;
}
