#include "main.h"

/**
* push - Pushes an element to the stack
* @stack: A pointer to the top of the stack
* @line_number: The current line number
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;

	int n;

	arg = strtok(NULL, DELIMS);
	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);
	add_node(stack, n);
}

/**
* pall - Prints all the values on the stack
* @stack: A pointer to the top of the stack
* @line_number: The current line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	char *arg;

	arg = strtok(NULL, DELIMS);
	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
* pint - Prints the value at the top of the stack
* @stack: A pointer to the top of the stack
* @line_number: The current line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
* pop - Removes the top element of the stack
* @stack: A pointer to the top of the stack
* @line_number: The current line number
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}

/**
* swap - Swaps the top two elements of the stack
* @stack: A pointer to the top of the stack
* @line_number: The current line number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
