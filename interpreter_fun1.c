#include "main.h"

void free_stack(stack_t **head);
int initialize_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_array_len(void);

/**
 * free_stack - Frees a stack of type stack_t.
 * @head: A pointer to the head (stack) or bottom (queue)
 *        of a stack_t
 *
 */
void free_stack(stack_t **head)
{
	stack_t *tmp = *head;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

/**
 * initialize_stack - Initializes a stack.
 * @stack: A pointer unintialized stack_t stack
 * Return: EXIT_SUCCESS on success and
 *          EXIT_FAILURE on failure
 */
int initialize_stack(stack_t **stack)
{
	stack_t *node = *stack;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
		return (malloc_error());

	node->n = STACK;
	node->prev = NULL;
	node->next = NULL;

	*stack = node;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks if stack_t is in stack or queue mode.
 * @stack: A pointer top stack of stack_t linked list.
 * Return: STACK(0) if stack_t is in stack mode and
 *          QUEUE(1) if stack_t is in queue mode
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

/**
 * free_tokens - Frees the global op_tokens of strings.
 *
 */
void free_tokens(void)
{
	size_t i;

	if (op_tokens == NULL)
		return;

	for (i = 0; op_tokens[i]; i++)
		free(op_tokens[i]);

	free(op_tokens);
}

/**
 * token_array_len - Get the length of the current op_tokens.
 *
 * Return: Length of the current op_tokens.
 */
unsigned int token_array_len(void)
{
	unsigned int token_len = 0;

	while (op_tokens[token_len])
		token_len++;
	return (token_len);
}
