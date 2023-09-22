#include "monty.h"

void set_token_error(int error_code)
{
	int token_length = 0, i = 0;

	char *exit_string = NULL;

	char **new_tokens = NULL;

	token_length = token_array_length();
	new_tokens = malloc(sizeof(char *) * (token_length + 2));
	if (!instruction_tokens)
	{
		malloc_fail();
		return;
	}
	while (i < token_length)
	{
		new_tokens[i] = instruction_tokens[i];
		i++;
	}
	exit_string = convert_int_to_str(error_code);
	if (!exit_string)
	{
		free(new_tokens);
		malloc_fail();
		return;
	}
	new_tokens[i++] = exit_string;
	new_tokens[i] = NULL;
	free(instruction_tokens);
	instruction_tokens = new_tokens;
}
