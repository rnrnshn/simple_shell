#include "shell.h"

/**
 * main - Entry point to the shell program
 * @argc: Number of command line arguments
 * @argv: Argument vector
 * @envp: environment variable
 *
 * Return: Always 0
 *
 */

int main(int argc, char *argv[], char *envp[])
{
	char *lineptr = NULL, *pathcmd = NULL, *path = NULL;
	size_t buffer_size = 0;
	ssize_t num_chars_read = 0;
	char **cmd = NULL, **paths = NULL;
	(void) envp, (void) argv;

	if (argc < 1)
		return (-1);
	signal(SIGINT, handle_sig);
	while (1)
	{
		free_cmds(cmd);
		free_cmds(paths);
		free(pathcmd);
		prompt_printer();
		num_chars_read = getline(&lineptr, &buffer_size, stdin);
		if (num_chars_read < 0)
			break;
		info.ln_count++;
		if (lineptr[num_chars_read - 1] == '\n')
			lineptr[num_chars_read - 1]  = '\0';
		cmd = tokenize(lineptr);
		if (cmd == NULL || *cmd == NULL || **cmd == '\0')
			continue;
		if (cmd_type(cmd, lineptr))
			continue;
		path = _getpath();
		paths = tokenize(path);
		pathcmd = search_path(paths, cmd[0]);
		if (pathcmd == NULL)
			perror(argv[0]);
		else
			exec_cmd(pathcmd, cmd);
	}
	if (num_chars_read < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(lineptr);
	return (0);
}

/**
 * prompt_printer - This program prints the prompt if the
 * shell is in interactive mode
 *
 * Return: void
 */
void prompt_printer(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}

/**
 * handle_sig - Allows ctrl+C to be printed by the shell
 * @n: signum
 *
 * Return: void
 */
void handle_sig(int n __attribute__((unused)))
{
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}

/**
 * cmd_type - Checks the command whether its a built-in or executable
 * with a pathname
 * @cmd: array of pointers to command line arguments
 * @b: lineptr returned by getline function
 *
 * Return: 1 if the command is executed, 0 otherwise
 */
int cmd_type(char **cmd, char *b)
{
	if (is_builtin(cmd, b))
	{
		return (1);
	}
	else if (**cmd == '/')
	{
		exec_cmd(cmd[0], cmd);
		return (1);
	}
	return (0);
}
