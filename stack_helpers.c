#include "monty.h"
/**
 * free_stack - Free stack.
 * @s_head: Head of the stack.
 * Return: Always 0.
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
