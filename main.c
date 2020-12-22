#include "monty.h"
globals_t gb;

/**
 * main - execute program monty.
 * @argc: number of arguments.
 * @argv: array of string arguments.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char **argv)
{
	gb.input = NULL;
	gb.line = NULL;
	gb.opcode = NULL;
	gb.s_head = NULL;
	gb.isqueue = 0;
	gb.ln = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	gb.input = fopen(argv[1], "r");
	if (gb.input == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	loop();
	fclose(gb.input);

	return (EXIT_SUCCESS);
}
