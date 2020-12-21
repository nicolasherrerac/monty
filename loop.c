#include "monty.h"

void _free(void)
{
	free_stack(gb.s_head);
        free(gb.line);
}

void loop(void)
{

	int read;
	size_t len;
	unsigned int line_number = 0;
	char *str_num = NULL;

	do {
        /* read */
		read = getline(&(gb.line), &len, gb.input);
        if(read == -1)
            break;
        (gb.ln)++;

        /* Parse */
        gb.opcode = strtok(gb.line, " \t\n");
	str_num = strtok(NULL, " \t\n");

        /* execute */
	if (!(gb.opcode))
		continue;
	else if (*(gb.opcode) == '#' || strcmp(gb.opcode, "nop") == 0)
	{
		free(gb.line);
		gb.line = NULL;
		continue;
	}
	else if (strcmp(gb.opcode, "push") == 0)
		push(&(gb.s_head), gb.ln, str_num);
	else
		execute();

        /* clean */
	free(gb.line);
	gb.line = NULL;
    }while(1);
        _free();
}
