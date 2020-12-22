#include "monty.h"
/**
 * _free - free memory.
 * Return: Always 0.
 */
void _free(void)
{
	free_stack(gb.s_head);
	free(gb.line);
}

/**
 * loop - read line, save line and execute line.
 * Return: Always 0.
 */
void loop(void)
{
	int read;
	size_t len;
	char *str_num = NULL;

	do {
		/* read */
		read = getline(&(gb.line), &len, gb.input);
		if (read == -1)
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
		else if (strcmp(gb.opcode, "stack") == 0)
			gb.isqueue = 0;
		else if (strcmp(gb.opcode, "queue") == 0)
			gb.isqueue = 1;
		else if (strcmp(gb.opcode, "push") == 0)
		{
			if (gb.isqueue)
				push_end(&(gb.s_head), str_num);
			else
				push(&(gb.s_head), str_num);
		}
		else
			execute();
		/* clean */
		free(gb.line);
		gb.line = NULL;
	} while (1);
	_free();
}
