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

/*command_handler*/
char *_getpath(void);
char **tokenize(char *str);
void exec_cmd(char *c, char **cmd);


/* built-ins prototypes */
void env_builtin(void);
void logout(char **cmd, char *b);
int is_builtin(char **cmd, char *b);
void prompt_printer(void);
void handle_sig(int n);

/* helper prototypes */
int cmd_type(char **cmd, char *b);
void free_cmds(char **m);


#endif /* __SHELL_H__ */
