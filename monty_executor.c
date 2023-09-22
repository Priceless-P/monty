#include "monty.h"

void free_token_memory(void);
unsigned int token_array_length(void);
int check_empty_line(char *line_content, char *delimiters);
void (*find_op_function(char *opcode))(stack_t**, unsigned int);
int execute_monty(FILE *file_handle);

void free_token_memory(void)
{
	size_t idx = 0;

	if (instruction_tokens == NULL)
		return;

	for (idx = 0; instruction_tokens[idx]; idx++)
		free(instruction_tokens[idx]);

	free(instruction_tokens);
}

unsigned int token_array_length(void)
{
	unsigned int token_length = 0;

	while (instruction_tokens[token_length])
		token_length++;
	return (token_length);
}

int check_empty_line(char *line_content, char *delimiters)
{
	int i, j;

	for (i = 0; line_content[i]; i++)
	{
		for (j = 0; delimiters[j]; j++)
		{
			if (line_content[i] == delimiters[j])
				break;
		}
		if (delimiters[j] == '\0')
			return (0);
	}

	return (1);
}

void (*find_op_function(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_functions[i].opcode; i++)
	{
		if (strcmp(opcode, op_functions[i].opcode) == 0)
			return (op_functions[i].f);
	}

	return (NULL);
}

int execute_monty(FILE *file_handle)
{
	stack_t *stack = NULL;
	char *line_content = NULL;

	size_t len = 0, exit_code = EXIT_SUCCESS;
	unsigned int line_num = 0, prev_token_length = 0;

	void (*op_function)(stack_t**, unsigned int);

	if (initialize_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line_content, &len, file_handle) != -1)
	{
		line_num++;
		instruction_tokens[0] = strtok(line_content, DELIMS);
		if (instruction_tokens == NULL)
		{
			if (check_empty_line(line_content, DELIMS))
				continue;
			release_stack(&stack);
			return (malloc_fail());
		}
		else if (instruction_tokens[0][0] == '#') /* comment line */
		{
			free_token_memory();
			continue;
		}
		op_function = find_op_function(instruction_tokens[0]);
		if (op_function == NULL)
		{
			release_stack(&stack);
			exit_code = invalid_instruction(instruction_tokens[0], line_num);
			free_token_memory();
			break;
		}
		prev_token_length = token_array_length();
		op_function(&stack, line_num);
		if (token_array_length() != prev_token_length)
		{
			if (instruction_tokens && instruction_tokens[prev_token_length])
				exit_code = atoi(instruction_tokens[prev_token_length]);
			else
				exit_code = EXIT_FAILURE;
			free_token_memory();
			break;
		}
		free_token_memory();
	}
	release_stack(&stack);

	if (line_content && *line_content == 0)
	{
		free(line_content);
		return (malloc_fail());
	}

	free(line_content);
	return (exit_code);
}
