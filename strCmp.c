#include "simple_shell.h"

/**
 * _strcmp- compare two string
 * @s1: string 1
 * @s2: string 2
 *
 * Return: retuns the strings differences
 *
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);

		}
		i++;

	}

	if (s1[i] == '\0' && s2[i] == '\0')
	{
		return (0);

	}

	else if (s1[i] == '\0')
	{
		return (-s2[i]);

	}
	else
	{
		return (s1[i]);

	}
}
