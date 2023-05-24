#include "simple_shell.h"

/**
 * _strcat- concatenate two string
 * @destination: destination string
 * @source: source string
 *
 * Return: retuns the destination string
 *
 */

char *_strcat(char *destination, const char *source)
{

	int i = 0, len = 0;

	while (destination[len] != '\0')
	{
		len++;
	}
	while (source[i] != '\0')
	{
		destination[len + i] = source[i];
		i++;

	}
	destination[len + i] = '\0';

	return (destination);

}
