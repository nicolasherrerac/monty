#include "monty.h"

/**
 * execute - Execute a opcode.
 * Return: The return value of the opcode executed.
 */
void execute(void)
{
	int i;
	instruction_t op_arr[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", m_div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}};

	for (i = 0; op_arr[i].opcode; i++)
	{
		if (strcmp(op_arr[i].opcode, gb.opcode) == 0)
			break;
	}
	if (op_arr[i].opcode != NULL)
	{
		op_arr[i].f(&(gb.s_head), gb.ln);
		return;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", gb.ln, gb.opcode);
	_free();
	fclose(gb.input);
	exit(EXIT_FAILURE);
}
