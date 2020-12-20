#include "monty.h"

/**
 * execute - Execute a opcode.
 * @head: List of arguments.
 * Return: The return value of the opcode executed.
 */
void execute(char *str_opcode, int line_number)
{
	int i;
	stack_t *stack = NULL;
	instruction_t op_arr[] = {
		/*{"push", push},*/
		{"pall", pall},
		{NULL, NULL}};

	for (i = 0; op_arr[i].opcode; i++)
	{
		if (strcmp(op_arr[i].opcode, str_opcode) == 0)
			break;
	}
	if (op_arr[i].opcode != NULL)
	{
		op_arr[i].f(&stack, line_number);
		return;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str_opcode);
	exit(EXIT_FAILURE);
}
