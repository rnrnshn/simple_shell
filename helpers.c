#include "shell.h"

/**
 * exec_cmd - This program creates a new child process
 * executes a command, and waits for the child process
 * to update its status
 * @c: command
 * @cmd: vector array of pointers to commands
 *
 * Return: void
 */

void exec_cmd(char *c, char **cmd)
{
	pid_t newProcess;
	int status;
	char **envp = environ;

	newProcess = fork();
	if (newProcess < 0)
		perror(c);
	if (newProcess == 0)
	{
		execve(c, cmd, envp);
		perror(c);
		free(c);
		free_cmds(cmd);
		exit(98);
	}
	else
	{
		wait(&status);
	}
}

/**
 * tokenize - splits a string into an array of tokens
 * @str: string to be tokenized and packaged
 *
 * Return: vector array of string tokens
 */

char **tokenize(char *str)
{
	size_t index = 0, io = 0;
	int tkn = 1;
	char **tokens = NULL;
	char *buf = NULL, *token = NULL, *bufptr = NULL, *delim = " :\t\r\n";

	buf = duplicate_str(str);
	if (buf == NULL)
		return (NULL);
	bufptr = buf;

	while (*bufptr)
	{
		if (check_str(delim, *bufptr) != NULL && io == 0)
		{
			tkn++;
			io = 1;
		}
		else if (check_str(delim, *bufptr) == NULL && io == 1)
			io = 0;
		bufptr++;
	}
	tokens = malloc(sizeof(char *) * (tkn + 1));
	token = strtok(buf, delim);
	while (token)
	{
		tokens[index] = duplicate_str(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = NULL;

	free(buf);
	return (tokens);
}

/**
 * free_cmds - This program frees the cmd array
 * @m: pointer to an array of command line
 * arguments
 *
 * Return: void
 */
void free_cmds(char **m)
{
	int index = 0;

	if (m == NULL)
		return;
	while (m[index])
	{
		free(m[index]);
		index++;
	}
	free(m);
}
