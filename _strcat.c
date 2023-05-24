#include <stdio.h>
#include <string.h>

char *_strcat(char *destination, const char *source)
{

	int i, len = 0;
	
	for (len = 0; destination[len] != '\0'; len++)

	while (source[i] !='\0')
	{
		destination[len + i] = source[i];
		i++;

	}
	destination[len + i] = '\0';
	
	return (destination);

}


int main()
{

	char s1[] = "Akia";
	char d1[] = "niti";
	_strcat(d1, s1);
	printf("%s\n", d1);
	printf("%s\n", d1);
	return (0);

}


