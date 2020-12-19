#include "monty.h"

int main(int argc, char *argv)
{
	FILE *input;
	int status;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return(EXIT_FAILURE);
	}

	input = fopen(argv[1], "r");
	if (input == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		return(EXIT_FAILURE);
	}
	status = loop(input);
	fclose(input);
	return(status);
}