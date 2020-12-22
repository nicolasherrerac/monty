#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args_s - list of arguments opcode give for user.
 * @arg: arguments.
 * @next: next node of the list.
 */
typedef struct args_s
{
	char *arg;
	struct args_s *next;
} args_t;

/**
 * struct globals_s - list of globals variables.
 * @input: Monty file.
 * @line: line of monty file.
 * @ln: Line number of the file.
 * @opcode: opcode of the line.
 * @s_head: Head of the stack.
 */
typedef struct globals_s
{
	FILE *input;
	char *line;
	char *opcode;
	stack_t *s_head;
	unsigned int ln;
} globals_t;

extern globals_t gb;

/* Main helpers*/
void loop(void);
void execute(void);

/*Opcode*/
void push(stack_t **s_head, char *str_num);
void pall(stack_t **s_head, unsigned int line_number);
void pint(stack_t **s_head, unsigned int line_number);
void pop(stack_t **s_head, unsigned int line_number);
void swap(stack_t **s_head, unsigned int line_number);
void add(stack_t **s_head, unsigned int line_number);
void sub(stack_t **s_head, unsigned int line_number);
void m_div(stack_t **s_head, unsigned int line_number);
void mul(stack_t **s_head, unsigned int line_number);
void mod(stack_t **s_head, unsigned int line_number);
void pstr(stack_t **s_head, unsigned int line_number);
void pchar(stack_t **s_head, unsigned int line_number);
void rotl(stack_t **s_head, unsigned int line_number);
void rotr(stack_t **s_head, unsigned int line_number);

/* Helpers*/
int isnum(char *str_num);
void free_stack(stack_t *s_head);
void prt_error(int n_error);
void _free(void);

#endif
