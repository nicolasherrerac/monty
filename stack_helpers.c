#include "monty.h"

/**
 * free_stack - Free stack.
 * @head: Head of the stack.
 */
void free_stack(stack_t *s_head)
{
	stack_t *tmp = s_head;

	for (; tmp; s_head = tmp)
	{
		tmp = s_head->next;
		free(s_head);
	}
}
