#include "monty.h"

/**
 * isnum - Check if the string is a number
 * @str_num: String with a number
 * Return: 1 if is number digit if not return 0
 */
int isnum(char *str_num)
{
	char *letter = str_num;

	if (str_num == NULL)
		return (0);
	if (*letter == '-')
		letter++;

	for (; *letter != '\0'; letter++)
	{
		if (*letter < '0' || *letter > '9')
			return (0);
	}
	return (1);
}

void push(stack_t **s_head, char *str_num)
{
	stack_t *new = NULL;
	int num;

	if (isnum(str_num) == 0)
		prt_error(-2);

	num = atoi(str_num);

	/*Create new node*/
	new = malloc(sizeof(stack_t));
	if (!new)
		prt_error(-1);

	new->n = num;
	new->prev = NULL;
	new->next = *s_head;

	if (*s_head)
		(*s_head)->prev = new;

	*s_head = new;
}

void pall(stack_t **s_head, unsigned int line_number)
{
	stack_t *node = *s_head;
	for (; node;)
	{
		printf("%d\n", node->n);
		node = node->next;
	}

	(void)line_number;
}
