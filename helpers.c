#include "main.h"

/**
* add_node - Adds a new node to the top of the stack
* @stack: A pointer to the top of the stack
* @n: The value to add to the stack
*
* Return: A pointer to the new node, or NULL on failure
*/
stack_t *add_node(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
	return (new_node);
}

/**
* mod - Computes the rest of the division of the
* second top element by the top element
* @stack: A pointer to the top of the stack
* @line_number: The current line number
*/
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
* queue - Sets the format of the data to a queue (FIFO)
* @stack: A pointer to the top of the stack
* @line_number: The current line number
*/
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

}

/**
* stack - Sets the format of the data to a stack (LIFO)
* @stack: A pointer to the top of the stack
* @line_number: The current line number
*/
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

}
