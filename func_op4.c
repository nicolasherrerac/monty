#include "monty.h"
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void pchar(stack_t **s_head, unsigned int line_number)
{
	if (s_head == NULL)
		return;

	if (*s_head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*s_head)->n < 0 || (*s_head)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	dprintf(STDOUT_FILENO, "%c\n", (*s_head)->n);
}
/**
 * pstr - rints the string starting at the top of the stack.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void pstr(stack_t **s_head, unsigned int line_number)
{
	stack_t *cp = *s_head;
	(void)line_number;

	while (cp != NULL && cp->n != 0)
	{
		if (cp->n < 0 || cp->n > 127)
			break;
		dprintf(STDOUT_FILENO, "%c\n", cp->n);
		cp = cp->next;
	}
	dprintf(STDOUT_FILENO, "\n");
}
