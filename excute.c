#include "monty.h"

/**
 * execute - Execute a opcode.
 * @head: List of arguments.
 * Return: The return value of the opcode executed.
 */
int execute(args_t *head)
{
	int i;
	instruction_s op_arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};

	for (i = 0; op_arr[i].opcode; i++)
	{
		if (strcmp(op_arr[i].opcode, head->arg) == 0)
			break;
	}
	if (op_arr[i].opcode != NULL)
	{
		return (op_arr[i].f(stack, line_number));
	}
	fprintf(stderr, "L%d: unknown instruction %s", line_number, head->arg)
	return ();
}
