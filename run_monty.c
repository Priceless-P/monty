#include "main.h"

/**
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t **, unsigned int);

	if (initialize_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_tokens = strtow(line, DELIMS);
		if (op_tokens == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_tokens[0][0] == '#') /* comment line */
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_tokens[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_instruct_error(op_tokens[0], line_number);
			free_tokens();
			break;
		}
		prev_tok_len = token_array_len();
		op_func(&stack, line_number);
		if (token_array_len() != prev_tok_len)
		{
			if (op_tokens && op_tokens[prev_tok_len])
				exit_status = atoi(op_tokens[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (exit_status);
}