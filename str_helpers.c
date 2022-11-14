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

/**
 * _strncmp - compares two strings up to n bytes
 * @first: first string to compare
 * @second: second string to compare
 * @n: the number of bytes in n to check
 *
 * Return: value < 0 if (first < second)
 * value > 0 if (first > second)
 * value = 0 if (first == second)
 */
int _strncmp(const char *first, const char *second, int n)
{
	int idx;

	for (idx = 0; first[idx] && second[idx] && idx < n; idx++)
	{
		if (first[idx] != second[idx])
			return (first[idx] - second[idx]);
	}
	return (0);
}

/**
 * _strlen - gets the length of a string
 * @str: string to evaluate
 *
 * Return: length of string
 */

int _strlen(const char *str)
{
	size_t i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
 * check_str - searches a string for a specific character
 * @str: string to examine
 * @chr: character to look for
 *
 * Return: pointer to index of first occurence, NULL if not found
 */

char *check_str(char *str, int chr)
{
	while (*str)
	{
		if (*str == chr)
			return (str);
		str++;
	}
	return (NULL);
}
