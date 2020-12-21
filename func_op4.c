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
		prt_error(-5);

	if ((*s_head)->n < 0 || (*s_head)->n > 127)
		prt_error(-6);

	dprintf(STDOUT_FILENO, "%c\n", (*s_head)->n);
	(void)line_number;
}

/**
 * pstr - rints the string starting at the top of the stack.
 * @s_head: First node.
 * @line_number: Currrent line number.
 */
void pstr(stack_t **s_head, unsigned int line_number)
{
	stack_t *cp = *s_head;

	if (s_head == NULL)
		return;

	while (cp != NULL && cp->n != 0)
	{
		if (cp->n < 0 || cp->n > 127)
			break;
		dprintf(STDOUT_FILENO, "%c", cp->n);
		cp = cp->next;
	}
	dprintf(STDOUT_FILENO, "\n");

	(void)line_number;
}
