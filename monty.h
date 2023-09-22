#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **instruction_tokens;

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

/* Error Handling */
int bad_usage(void);
int open_file_err(char *file);
int invalid_instruction(char *line_num, char opcode);
int malloc_fail(void);
int arg_type_error(unsigned int line_num);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
void set_token_error(int error_code);
int pint_error(unsigned int line_number);

/* Main functions */
int execute_monty(FILE *file_handle);
void (*find_op_function(char *opcode))(stack_t **, unsigned int);
int check_empty_line(char *line_content, char *delimiters);
void free_token_memory(void);
unsigned int token_array_length(void);

/* Stack functions */
void release_stack(stack_t **stack);
int initialize_stack(stack_t **stack);
int determine_mode(stack_t *stack);

/* String manipulation functions */
char **split_string(char *str, char *delims);
int is_delimiter(char ch, char *delims);
int get_word_len(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *find_next_word(char *str, char *delims);

/* Integer to string conversion functions */
char *convert_int_to_str(int num);
unsigned int absolute_value(int);
int get_num_base_len(unsigned int num, unsigned int base);
void fill_num_base_buffer(unsigned int num, unsigned int base,
char *buffer, int buffer_size);

#endif /* MONTY_H */
