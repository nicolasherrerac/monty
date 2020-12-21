#include "monty.h"

void loop(FILE *input, stack_t *s_head)
{

	int read;
	size_t len;
	unsigned int line_number = 0;
	char *line = NULL, *opcode = NULL, *str_num = NULL;

	do {
        /* read */
        read = getline(&line, &len, input);
        if(read == -1)
            break;
        line_number++;

        /* Parse */
        opcode = strtok(line, " \t\n");
	str_num = strtok(NULL, " \t\n");

        /* execute */
	if (!opcode)
		continue;
	else if (*opcode == '#' || strcmp(opcode, "nop") == 0)
		continue;
	else if (strcmp(opcode, "push") == 0)
		push(&s_head, line_number, str_num);
	else
		execute(opcode, line_number, s_head);

        /* clean */

	free(line);
	line = NULL;
    }while(1);

	free(line);
}
