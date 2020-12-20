#include "monty.h"

int loop(FILE *input)
{

	int read;
	size_t len;
	unsigned int line_number = 0;
	char *line = NULL, *cpy = NULL, *arg = NULL, *aux = NULL;
	args_t *arguments = NULL;
	int status = 0;

	do {
        /* read */
        read = getline(&line, &len, input);
        if(read == -1)
            break;
        line_number++;

        /* Parse */

        cpy = strdup(line);
	aux = cpy;

        for (; (arg = strtok(cpy, " \t\n")); cpy = NULL, add(&arguments, arg))
            if(arg == NULL)
	    break;

        /* execute */
	status = execute(arguments, line_number);
        /* clean */

        deleteArgs(arguments);
	free(line);
	free(aux);
	line = NULL;
	arguments = NULL;

    }while(1);

	free(line);
    return (status);
}
