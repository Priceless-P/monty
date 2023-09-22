#include <sys/stat.h>
#include <fcntl.h>
#include "monty.h"

char **instruction_tokens = NULL;
int main(int arg_count, char **arg_values)
{
	FILE *file_handle = NULL;
	int exit_status = EXIT_SUCCESS;

	if (arg_count != 2)
		return (bad_usage());
	file_handle = fopen(arg_values[1], "r");
	if (file_handle == NULL)
		return (open_file_err(arg_values[1]));
	exit_status = execute_monty(file_handle);
	fclose(file_handle);
	return (exit_status);
}
