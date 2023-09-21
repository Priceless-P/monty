#include "main.h"

/**
* monty_execute - Execute Monty bytecode instruction
* @opcode: The opcode to execute.
* args: The arguments (if any) for the opcode.
* @head: A pointer to the stack.
* @line_num: The current line number in the Monty bytecode file.
*
* Description: This function executes a Monty bytecode instruction based on
* the provided opcode. It looks up the corresponding function in
* the OpcodeTable, passes the relevant arguments, and executes the function.
*
* Return: If successful, returns 0. If an error occurs, returns -1.
*/
int monty_execute(char *opcode, stack_t **head,

unsigned int line_num)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		/*
		  *{"pall", pall},
		// {"pint", pint},
		 {"pop", pop},
		 */

		{NULL, NULL}};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(head, line_num);
			return (0);
		}
	}
	invalid_instruction(line_num, (*opcode));
	return (-1);
}

/**
 * add_nodeint_end- Adds a new node at the end of a linked list.
 *
 * @stack: A pointer to the head of the linked list.
 * @n The data to be stored in the new node.
 *
 * Return: None
 */
void add_nodeint_end(stack_t **stack, int n)
{
	stack_t *new_node, *current;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

/**
 * is_number - checks if a string is a number
 * @arg: the string to check
 *
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(char *arg)
{
	int i;

	if (arg == NULL)
		return (0);

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (0);
	}

	return (1);
}

/**
 * getline_ - Custom implementation of the getline function.
 *
 * @lineptr: A pointer to a pointer to the buffer for the line.
 * @n: A pointer to the size of the buffer.
 * @stream: The input stream (e.g., a file pointer) to read from.
 *
 * Return: On success, the number of characters read (including the newline
 * character), or -1 on failure (e.g., end of file, memory allocation error,
 * or line too long for the buffer).
 */

size_t getline_(char **lineptr, size_t *n, FILE *stream) {
	size_t bufsize = 1024;
	size_t pos = 0;
	int c;

	if (*lineptr == NULL) {
		*lineptr = (char *)malloc(bufsize);
		if (*lineptr == NULL)
		{
			malloc_fail();
		}
		*n = bufsize;
	}
	while (1) {
		c = fgetc(stream);

		if (c == EOF) {
			if (pos == 0)
			{
				return (-1);
			}
			break;
		}
		if (pos >= *n - 1) {
			return (-1);
		}

		(*lineptr)[pos++] = (char)c;

		if (c == '\n') {
			break;
		}
	}

	(*lineptr)[pos] = '\0';
	return (size_t)pos;
}
