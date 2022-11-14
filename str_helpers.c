#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @s1:First string
 * @s2: Second string
 *
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	int tot;

	if (s1 == NULL || s2 == NULL)
		return (0);

	while (*s1 && *s2)
	{
		tot = *s1 - *s2;

		if (tot != 0)
			break;
		s1++;
		s2++;
	}
	return (tot);

}

/**
 * duplicate_str - returns a pointer to a newly allocated
 * space in memory, which contains a copy of the
 * string given as a parameter
 * @str: string to be duplicated
 *
 * Return: pointer to the duplicated string
 * or NULL if it fails
 */

char *duplicate_str(char *str)
{
	char *p;
	int i, len;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);

	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; *str != '\0'; str++, i++)
	{
		p[i] = str[0];
	}
	p[i++] = '\0';

	return (p);
}
