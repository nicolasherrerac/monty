#include "monty.h"

char *line = NULL;

void _free(void)
{
	free_stack(s_head);
        free(line);
}

void loop(FILE *input)
{

	int read;
	size_t len;
	unsigned int line_number = 0;
	char *opcode = NULL, *str_num = NULL;

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
		execute(opcode, line_number);

        /* clean */
	free(line);
	line = NULL;
    }while(1);
        _free();
}
