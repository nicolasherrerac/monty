#include "monty.h"

void push(stack_t **s_head, unsigned int line_number, char *str_num)
{
	stack_t *new = NULL;
	int num;
	printf("Entra al push con %s\n", str_num);
	/*Create new node*/
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/*if (!isnum(str_num))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
		}*/
	num = atoi(str_num);

	new->n = num;
	new->prev = NULL;
	new->next = *s_head;

	if (*s_head)
		(*s_head)->prev = new;

	*s_head = new;
}

void pall(stack_t **s_head, unsigned int line_number)
{
	stack_t *nodo = *s_head;
	printf("Entra al pall\n");
	for (; nodo;)
	{
		printf("%d\n", nodo->n);
		nodo = nodo->next;
	}
}
