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

void prompt_printer(void);
void handle_sig(int n);

#endif /* __SHELL_H__ */
