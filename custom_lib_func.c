#include "main.h"

char *char_convert(int num);
unsigned int absolute_num(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
	char *buff, int buff_size);

/**
 * char_convert - gets a character pointer to a new string containing int
 * @num: number to be worked on.
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *char_convert(int num)
{
	unsigned int temp;
	int length = 0;
	long long_num = 0;
	char *string;

	temp = absolute_num(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || long_num < 0)
		length++;
	string = malloc(length + 1);

	if (!string)
		return (NULL);

	if (num < 0 || long_num < 0)
		string[0] = '-';

		return (string);
}

/**
 * absolute_num - gets the absolute value of an integer
 * @i: integer to be worked on
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int absolute_num(int i)
{
	if (i < 0)
		return (-(unsigned int (i)))
	return ((unsigned int)i);
}

/**
 * get_numbase_len - gets length of buffer needed for an unsigned int
 * @num: number to be worked on
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length of buffer needed
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - fills buffer with correct numbers up to base 36
 * @num: number to be worked on
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
	char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
