#include "simple_shell.h"

/**
 * _strcat - a function that concatenates two strings.
 * @dest: first string
 * @src: second string
 * Return: A pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (temp);
}
