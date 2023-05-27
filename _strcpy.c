#include "simple_shell.h"

/**
 * _strcpy - A function that copies a string from one place to another
 * @dest: address of string
 * @src: address of the strin
 * Return: A pointer to new string
 */
char *_strcpy(char *dest, char *src)
{
	char *str = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (str);
}
