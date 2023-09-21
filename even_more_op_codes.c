#include "main.h"

/**
* pchar - Prints the char at the top of the stack, followed by a new line.
* @stack: Stack to be printed.
* @line_number: Current line number.
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_value = (*stack)->n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(ascii_value);
	putchar('\n');
}

/**
 * pstr - Prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: Stack to be printed.
 * @line_number: Current line number.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;
	while (temp != NULL && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the stack to the top..
 *
 * @stack: The value to be rotated.
 * @line_number: The number of positions to rotate the bits to the left.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int first_value = 0;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		first_value = (*stack)->n;
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
		add_nodeint_end(stack, first_value);
	}
}

/**
 * rotr - Rotates the stack to the bottom.
 *
 * @stack: The value to be rotated.
 * @line_number: The number of positions to rotate the bits to the left.
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	int temp;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
	{
		last = last->next;
	}
	temp = last->n;
	last->prev->next = NULL;
	free(last);

	push(stack, temp);
}
