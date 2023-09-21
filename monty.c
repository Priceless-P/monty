#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
* main - Entry point for the Monty interpreter
* @argc: The number of arguments passed to the program
* @argv: An array of strings containing the arguments
*
* Return: 0 on success, 1 on failure
*/
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	size_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	size_t i = -1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline_(&line, &len, file)) != i)
	{
		line_number++;
		if (parse_line(line, &stack, line_number) == EXIT_FAILURE)
		{
			free_stack(stack);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(stack);
	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
* parse_line - Parses a line of Monty bytecode
* @line: The line to parse
* @stack: A pointer to the top of the stack
* @line_number: The current line number
*
* Return: 0 on success, 1 on failure
*/
int parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;

	instruction_t *instruction;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return (EXIT_SUCCESS);

	instruction = get_instruction(opcode);
	if (instruction == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		return (EXIT_FAILURE);
	}

	instruction->f(stack, line_number);
	return (EXIT_SUCCESS);
}

/**
* get_instruction - Gets the instruction associated with an opcode
* @opcode: The opcode to search for
*
* Return: A pointer to the instruction struct, or NULL if not found
*/
instruction_t *get_instruction(char *opcode)
{
	int i;
	instruction_t *instructions = malloc(sizeof(instruction_t) * 17);

	if (instructions == NULL)
	{
		malloc_fail();
	}

	instructions[0].opcode = "push";
	instructions[0].f = push;
	instructions[1].opcode = "pall";
	instructions[1].f = pall;
	instructions[2].opcode = "pop";
	instructions[2].f = pop;
	instructions[3].opcode = "pint";
	instructions[3].f = pint;
	instructions[4].opcode = "swap";
	instructions[4].f = swap;
	instructions[5].opcode = "add";
	instructions[5].f = add;
	instructions[6].opcode = "nop";
	instructions[6].f = nop;
	instructions[7].opcode = "sub";
	instructions[7].f = sub;
	instructions[8].opcode = "div";
	instructions[8].f = divide;
	instructions[9].opcode = "mul";
	instructions[9].f = mul;
	instructions[10].opcode = "mod";
	instructions[10].f = mod;
	instructions[11].opcode = "pchar";
	instructions[11].f = pchar;
	instructions[12].opcode = "pstr";
	instructions[12].f = pstr;
	instructions[13].opcode = "rotl";
	instructions[13].f = rotl;
	instructions[14].opcode = "rotr";
	instructions[14].f = rotr;
	instructions[15].opcode = "stack";
	instructions[15].f = stack;
	instructions[16].opcode = "queue";
	instructions[16].f = queue;
	instructions[17].opcode = NULL;
	instructions[17].f = NULL;
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (&instructions[i]);
	}

	return (NULL);
}

/**
* free_stack - Frees a stack
* @stack: A pointer to the top of the stack
*/
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
