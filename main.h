#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_MODE 0
#define QUEUE_MODE 1
#define DELIMS " \n\t\a\b"

extern char **op_toks;
extern int queue_mod;
/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
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
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
		char *opcode;

		void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;

/* functions */

void print_stack(stack_t *stack);
int parse_line(char *line, stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

/* Error functions*/
int bad_usage(void);
int open_file_err(char *file);
int invalid_instruction(int line_num, char opcode);
int malloc_fail(void);
int arg_type_error(char *line_num);

/* Helper functions */

int monty_execute(char *opcode, stack_t **head,
unsigned int line_num);
void add_nodeint_end(stack_t **stack, int n);
instruction_t *get_instruction(char *opcode);
stack_t *add_node(stack_t **stack, int n);
void free_stack(stack_t *stack);
int is_number(char *arg);
size_t getline_(char **lineptr, size_t *n, FILE *stream);

#endif /* MAIN_H */
