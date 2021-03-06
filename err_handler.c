#include "monty.h"

/**
 * prt_error - Print the corresponding message error according
 * to the error number.
 * @n_error: Error number.
 */
void prt_error(int n_error)
{
	/*Get message*/
	if (n_error == -1)
		fprintf(stderr, "Error: malloc failed\n");
	else if (n_error == -2)
		fprintf(stderr, "L%u: usage: push integer\n", gb.ln);
	else if (n_error == -3)
		fprintf(stderr, "L%u: can't %s an empty stack\n", gb.ln, gb.opcode);
	else if (n_error == -4)
		fprintf(stderr, "L%u: can't %s, stack too short\n", gb.ln, gb.opcode);
	else if (n_error == -5)
		fprintf(stderr, "L%u: can't pchar, stack empty\n", gb.ln);
	else if (n_error == -6)
		fprintf(stderr, "L%u: can't pchar, value out of range\n", gb.ln);
	else if (n_error == -31)
		fprintf(stderr, "L%u: can't %s, stack empty\n", gb.ln, gb.opcode);
	else if (n_error == -7)
		fprintf(stderr, "L%d: division by zero\n", gb.ln);
	_free();
	fclose(gb.input);
	exit(EXIT_FAILURE);
}
