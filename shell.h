#ifndef __SHELL_H__
#define __SHELL_H__

/*libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>

/*string_handlers*/
char *duplicate_str(char *str);
char *check_str(char *str, int chr);
int _strlen(const char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *first, const char *second, int n);

/*command_handler*/
char *_getpath(void);
char **tokenize(char *str);
void exec_cmd(char *c, char **cmd);
char *append_path(char *path, char *cmd);
char *search_path(char **p, char *cmd);

/*built-ins*/
void env_builtin(void);
void logout(char **cmd, char *b);
int is_builtin(char **cmd, char *b);
void prompt_printer(void);
void handle_sig(int n);

/*helper function*/
int cmd_type(char **cmd, char *b);
void free_cmds(char **m);

/*environment variables*/
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern char **environ;

/**
 * struct builtins - Handles builtins
 * @env: First member
 * @exit: Second member
 *
 * Description: builtin commands
 */
struct builtins
{
	char *env;
	char *exit;

} builtins;


/**
 * struct info - Status info struct
 * @final_exit: First member
 * @ln_count: Second member
 *
 * Description: Used in error handling
 */
struct info
{
	int final_exit;
	int ln_count;
} info;


/**
 * struct flags - Holds flags
 * @interactive: First member
 *
 * Description: used to handle
 *
 * boolean switches
 */
struct flags
{
	bool interactive;
} flags;


#endif /* __SHELL_H__ */
