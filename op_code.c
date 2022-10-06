#include "main.h"

/**
 * get_op_func - Matches an opcode withe coreesponding function.
 * @opcode: The opcode to be match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t op_func[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}};
	int i;

	for (i = 0; op_func[i].opcode; i++)
	{
		if (strcmp(opcode, op_func[i].opcode) == 0)
			return (op_func[i].f);
	}

	return (NULL);
}
