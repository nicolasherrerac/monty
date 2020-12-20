#include "monty.h"

void push(stack_t **s_head, int line_number)
{
	stack_t *new = NULL;
	char *str_num = NULL;
	int num;

	/*Create new node*/
	new = malloc(sizeof(stack_t));
	if (!new)
		fprintf(stderr, "Error: malloc failed");
	return (EXIT_FAILURE);

	str_num = data->arg;
	num = atoi(str_num);
	if (num = 0 && str_num[0] != 0)
		fprintf(stderr, "Error: atoi failed");
	return (EXIT_FAILURE);

	new->n = num;
	new->prev = NULL;
	new->next = *s_head;

	if (*s_head)
		(*s_head)->prev = new;

	*s_head = new;
}

void pall(stack_t **s_head, int line_number)
{
	int i;
	const stack_t *nodo = *s_head;

	for (i = 0; nodo != NULL; i++)
	{
		printf("%d\n", nodo->n);
		nodo = nodo->next;
	}
}
