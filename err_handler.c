#include "monty.h"

/**
 * prt_error - Print the corresponding message error according
 * to the error number.
 * @n_error: Error number.
 */
void prt_error(int n_error, unsigned int line_number)
{
	/*Get message*/
	switch (n_error)
	{
	case -1:
		fprintf(stderr, "Error: malloc failed\n");
		_free();
		break;
	case -2:
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		_free();
		break;
	case -3:
                fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
                free(gb.line);
                break;
	case -4:
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(gb.line);
		break;
	case -5:
                fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
                _free();
                break;
	case -6:
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                _free();
                break;
	}

	/*Print error message*/
	//prt_stde(msg_err);

	/*if (msg_err)
	  free(msg_err);*/
	fclose(gb.input);
	exit(EXIT_FAILURE);
}
