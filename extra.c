#include "monty.h"

void release_stack(stack_t **stack);
int initialize_stack(stack_t **stack);
int determine_mode(stack_t *stack);

void release_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int initialize_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_fail());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

int determine_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

#include <stdlib.h>

char **split_string(char *str, char *delims);

int is_delimiter(char ch, char *delims);

int get_word_len(char *str, char *delims);

int get_word_count(char *str, char *delims);

char *find_next_word(char *str, char *delims);

char **split_string(char *str, char *delims)
{
	char **words = NULL;

	int word_count, word_length, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	word_count = get_word_count(str, delims);

	if (word_count == 0)
		return (NULL);
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < word_count)
	{
		word_length = get_word_len(str, delims);
		if (is_delimiter(*str, delims))
		{
			str = find_next_word(str, delims);
		}
		words[i] = malloc((word_length + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < word_length)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = find_next_word(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

int is_delimiter(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int get_word_len(char *str, char *delims)
{
	int w_len = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			w_len++;
		}
		if (w_len > 0 && is_delimiter(str[i], delims))
			break;
		i++;
	}
	return (w_len);
}

int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

char *find_next_word(char *str, char *delims)
{
	int pending = 0;

	int i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}

#include <stdlib.h>

char *convert_int_to_str(int num);

unsigned int absolute_value(int);
int get_num_base_len(unsigned int num, unsigned int base);

void fill_num_base_buffer(unsigned int num, unsigned int base,

						char *buffer, int buffer_size);

char *convert_int_to_str(int num)
{
	unsigned int temp;

	int length = 0;

	long num_l = 0;

	char *result;

	temp = absolute_value(num);
	length = get_num_base_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++;
	result = malloc(length + 1);
	if (!result)
		return (NULL);

	fill_num_base_buffer(temp, 10, result, length);
	if (num < 0 || num_l < 0)
		result[0] = '-';

	return (result);
}

unsigned int absolute_value(int i)
{
	if (i < 0)
		return (-(unsigned int)i);

	return ((unsigned int)i);

}

int get_num_base_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

void fill_num_base_buffer(unsigned int num, unsigned int base,

	char *buffer, int buffer_size)
{
	int remainder, i = buffer_size - 1;

	buffer[buffer_size] = '\0';
	while (i >= 0)
	{
		remainder = num % base;
		if (remainder > 9)
			buffer[i] = remainder + 87;
		else
			buffer[i] = remainder + '0';
		num /= base;
		i--;
	}
}
