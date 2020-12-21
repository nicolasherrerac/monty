#include <monty.h>
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void pint(stack_t **s_head, int line_number)
{
	if ((*s_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		return (EXIT_FAILURE);
	}
	printf("%d", (*s_head)->next->n);
}
/**
 * pop - removes the top element of the stack.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void pop(stack_t **s_head, int line_number)
{
	stack_t *next = NULL;

	if ((*s_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		return (EXIT_FAILURE);
	}

	next = (*s_head)->next->next;
	free((*s_head)->next);
	if (next)
		next->prev = *s_head;
	(*s_head)->next = next;
}
/**
 * swap - swaps the top two elements of the stack.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void swap(stack_t **s_head, int line_number)
{
	stack_t *temp;

	if (*s_head == NULL || (*s_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		return (EXIT_FAILURE);
	}

	temp = (*s_head)->next;
	(*s_head)->prev = temp;
	(*s_head)->next = temp->next;
	temp->next = (*s_head);
	temp->prev = NULL;
	*s_head = temp;
}
