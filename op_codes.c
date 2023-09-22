#include "monty.h"

void push(stack_t **stack, unsigned int line_number);

void pall(stack_t **stack, unsigned int line_number);

void pint(stack_t **stack, unsigned int line_number);

void pop(stack_t **stack, unsigned int line_number);

void swap(stack_t **stack, unsigned int line_number);

void push(stack_t **stack, unsigned int line_number)
{

	stack_t *tmp, *new;
	int i;

(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_token_error(malloc_fail());
		return;
	}

	if (instruction_tokens[1] == NULL)
	{
		return;
	}

	for (i = 0; instruction_tokens[1][i]; i++)
	{
		if (instruction_tokens[1][i] == '-' && i == 0)
			continue;
		if (instruction_tokens[1][i] < '0' || instruction_tokens[1][i] > '9')
		{
			return;
		}
	}
	new->n = atoi(instruction_tokens[1]);

	if (determine_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
	free(new);
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_token_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_token_error(pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_token_error(short_stack_error(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
