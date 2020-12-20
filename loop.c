#include "monty.h"

void loop(FILE *input)
{

	int read;
	size_t len;
	unsigned int line_number = 0;
	char *line = NULL, *opcode = NULL, *str_num = NULL;
	stack_t *stack = NULL;

	do {
        /* read */
        read = getline(&line, &len, input);
        if(read == -1)
            break;
        line_number++;

        /* Parse */
        opcode = strtok(line, " \t\n");
	str_num = strtok(NULL, " \t\n");
	printf("num %s\n", str_num);
        /* execute */
	if (strcmp(opcode, "push") == 0)
	{
		if (str_num)
			push(&stack, line_number, str_num);
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
		execute(opcode, line_number);

        /* clean */

	free(line);
	line = NULL;
    }while(1);

	free(line);
}
