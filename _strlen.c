#include "simple_shell.h"

/**
 * _strlen - A function that finds the length of the string
 * @s: The input string
 * Return: The length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _atoi - a function that converts string to intege
 * @s: string
 * Return: integer fro
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char flag = 0;

	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		if (*s >= '0' && *s <= '9')
		{
			flag = 1;
			total = total * 10 + (*s - '0');
		}
		else if (*s < '0' || *s > '9')
		{
			if (flag == 1)
				break;
		}
		s++;
	}
	if (sign < 0)
		total = (-1 * (total));
	return (total);
}
