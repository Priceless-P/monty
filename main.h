#ifndef __MAIN_H__
#define __MAIN_H__

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_tokens;
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
/* Opcode Functions */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/* Interpreter Functions */
void free_stack(stack_t **head);
int initialize_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_array_len(void);
int is_empty_line(char *line, char *delims);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);

/* Custom Library Functions */
char **strtow(char *str, char *delims);
char *char_convert(int num);
unsigned int absolute_num(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
	char *buff, int buff_size);

/* Error Messages and codes */
int usage_error(void);
int malloc_error(void);
int fopen_error(char *filename);
int unknown_instruct_error(char *opcode, unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

#endif /* __MAIN_H__ */
