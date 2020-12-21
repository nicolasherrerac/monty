#include <monty.h>
/**
 * add - adds the top two elements of the stack.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void add(stack_t **s_head, unsigned int line_number)
{
	stack_t *temp;

	if (s_head == NULL)
		return;

	if (*s_head == NULL || (*s_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	(*s_head)->next->n += (*s_head)->n;
	temp = *s_head;
	*s_head = (*s_head)->next;
	(*s_head)->prev = NULL;
	free(temp);
}
/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void sub(stack_t **s_head, unsigned int line_number)
{
	stack_t *temp;

	if (s_head == NULL)
		return;

	if (*s_head == NULL || (*s_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	(*s_head)->next->n -= (*s_head)->n;
	temp = *s_head;
	*s_head = (*s_head)->next;
	(*s_head)->prev = NULL;
	free(temp);
}
/**
 * div -  divides the second top element of the
 * stack by the top element of the stack.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void div(stack_t **s_head, unsigned int line_number)
{
	stack_t *temp;

	if (s_head == NULL)
		return;

	if (*s_head == NULL || (*s_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	(*s_head)->next->n /= (*s_head)->n;
	temp = *s_head;
	*s_head = (*s_head)->next;
	(*s_head)->prev = NULL;
	free(temp);
}
/**
 * mul - multiplies the second top element of the
 * stack with the top element of the stack.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void mul(stack_t **s_head, unsigned int line_number)
{
	stack_t *temp;

	if (s_head == NULL)
		return;

	if (*s_head == NULL || (*s_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	(*s_head)->next->n *= (*s_head)->n;
	temp = *s_head;
	*s_head = (*s_head)->next;
	(*s_head)->prev = NULL;
	free(temp);
}
/**
 * mod - computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void mod(stack_t **s_head, unsigned int line_number)
{
	stack_t *temp;

	if (s_head == NULL)
		return;

	if (*s_head == NULL || (*s_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	(*s_head)->next->n %= (*s_head)->n;
	temp = *s_head;
	*s_head = (*s_head)->next;
	(*s_head)->prev = NULL;
	free(temp);
}
