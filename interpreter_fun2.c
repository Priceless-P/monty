#include "main.h"

int is_empty_line(char *line, char *delims);

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 *@line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: (1) If the line only contains delimiters .
 *         Otherwise (0).
 */

int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}
