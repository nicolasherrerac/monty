#include "monty.h"

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
		prt_error(-4);

	(*s_head)->next->n += (*s_head)->n;
	temp = *s_head;
	*s_head = (*s_head)->next;
	(*s_head)->prev = NULL;
	free(temp);

	(void)line_number;
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
		prt_error(-4);

	(*s_head)->next->n -= (*s_head)->n;
	temp = *s_head;
	*s_head = (*s_head)->next;
	(*s_head)->prev = NULL;
	free(temp);

	(void)line_number;
}

/**
 * m_div -  divides the second top element of the
 * stack by the top element of the stack.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void m_div(stack_t **s_head, unsigned int line_number)
{
	stack_t *temp;

	if (s_head == NULL)
		return;

	if (*s_head == NULL || (*s_head)->next == NULL)
		prt_error(-4);

	if ((*s_head)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*s_head)->next->n /= (*s_head)->n;
	temp = *s_head;
	*s_head = (*s_head)->next;
	(*s_head)->prev = NULL;
	free(temp);

	(void)line_number;
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
		prt_error(-4);

	(*s_head)->next->n *= (*s_head)->n;
	temp = *s_head;
	*s_head = (*s_head)->next;
	(*s_head)->prev = NULL;
	free(temp);

	(void)line_number;
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
		prt_error(-4);

	(*s_head)->next->n %= (*s_head)->n;
	temp = *s_head;
	*s_head = (*s_head)->next;
	(*s_head)->prev = NULL;
	free(temp);

	(void)line_number;
}
