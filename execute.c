#include "monty.h"

/**
 * execute - Execute a opcode.
 * @head: List of arguments.
 * Return: The return value of the opcode executed.
 */
void execute(char *str_opcode, int line_number)
{
	int i;
	instruction_t op_arr[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}};

	for (i = 0; op_arr[i].opcode; i++)
	{
		if (strcmp(op_arr[i].opcode, str_opcode) == 0)
			break;
	}
	if (op_arr[i].opcode != NULL)
	{
		op_arr[i].f(&s_head, line_number);
		return;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str_opcode);
	_free();
	exit(EXIT_FAILURE);
}
