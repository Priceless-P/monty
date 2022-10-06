#include "main.h"
/**
 * set_op_tok_error - Sets last element of op_tokens to be an error code.
 * @error_code: Integer to store as a string in op_tokens.
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_array_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_tokens)
	{
		malloc_error();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_tokens[i];
		i++;
	}
	exit_str = char_convert(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_tokens);
	op_tokens = new_toks;
}
