#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
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

	/*Find the last node*/
	for (; current->next; current = current->next)
		current->n = current->next->n;

	current->n = tmp;

	(void)line_number;
}
