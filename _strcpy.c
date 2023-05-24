#include "simple_shell.h"

/**
 * _strcpy- copy strings
 * @destination: array to copy to
 * @source: array to copy from
 *
 * Return: char of destination
 */

char *_strcpy(char *destination, const char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}

	destination[i] = '\0';

	return (destination);
}
