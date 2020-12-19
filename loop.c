#include "monty.h"

int loop(FILE *)
{
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


        pid = fork();
        if(pid == -1)
            return (-1);
        else if(pid == 0)
        {
            ret = execve(args[0], args, env);
            if (ret == -1)
                return -1;
        }
        else {  
            wait(&status);
        }


        /* clean */

        deleteArgs(arguments),free(line), free(args), free(cpy);
        arguments = NULL;
        
    }while(1);

    return (0);
}
}
