#include "monty.h"

int loop(FILE *input)
{

	int read;
	size_t len;
	unsigned int line_number;
	char *line = NULL, *cpy = NULL, *arg = NULL; *args = NULL;
	args_t *arguments = NULL;
	int status;

	do {
        /* read */

        read = getline(&line, &len, stdin);
        if(read == -1)
            break;
        line_number++;

        /* Parse */

        cpy = strdup(line);

        for (; (arg = strtok(cpy, " \t\n")); cpy = NULL, add(&arguments, arg)) 
            if(arg == NULL)
                break;
        /* execute */
	status = execute(arguments);
        /* clean */

        deleteArgs(arguments),free(line), free(args), free(cpy);
        arguments = NULL, line = NULL;

    }while(1);

    return (status);
}
