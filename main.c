#include "monty.h"

int main(int argc, char **argv)
{
	FILE *input = NULL;
	stack_t *s_head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	input = fopen(argv[1], "r");
	if (input == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	loop(input, s_head);
	fclose(input);
	return(EXIT_SUCCESS);
}
