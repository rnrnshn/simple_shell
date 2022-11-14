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
