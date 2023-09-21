#include "main.h"

/**
 * bad_usage - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int bad_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * open_file_err - Handles the error that occurs when opening a file.
 *
 * @file: The name of the file that failed to open.
 *
 * Return: (EXIT_FAILURE) always.
 */
int open_file_err(char *file)
{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		return (EXIT_FAILURE);
}

/**
 * invalid_instruction - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_num: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int invalid_instruction(int line_num, char opcode)
{
		fprintf(stderr, "L%d: unknown instruction %c\n", line_num, opcode);
		return (EXIT_FAILURE);
}

/**
 * malloc_fail - Handles a failed memory allocation.
 *
 * This function is called when a memory allocation using malloc fails.
 * It prints an error message and terminates the program.
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_fail(void)
{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
}

/**
 * arg_type_error - Prints invalid monty_push argument error messages.
 * @line_num: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int arg_type_error(char *line_num)
{
		fprintf(stderr, "L%s: usage: push integer", line_num);
		return (EXIT_FAILURE);
}
