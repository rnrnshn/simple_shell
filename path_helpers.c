#include "shell.h"

/**
 * _getpath - This functions finds and return the PATH
 * variable for the global environment vector
 *
 * Return: PATH, if found, or NULL
 */

char *_getpath(void)
{
	int i = 0;
	char **env = environ;
	char *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && i < 5)
			{
				path++;
				i++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}

/**
 * search_path - searches for PATH dir
 * containing command
 * @p: first operand
 * @cmd: second operand
 *
 * Return: unsigned int character count
 */

char *search_path(char **p, char *cmd)
{
	int i = 0;

	char *ret;

	while (p[i])
	{
		ret = append_path(p[i], cmd);
		if (access(ret, F_OK | X_OK) == 0)
		{
			return (ret);
		}
		else
			free(ret);
		i++;
	}
	return (NULL);
}
